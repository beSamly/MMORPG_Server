#include "pch.h"
#include "GameSystemUpdater.h"
#include "PacketDef.h"
#include "VECTOR3.pb.h"
#include "NPC.h"
#include "TransformEntity.h"
#include "POSITION_UPDATE.pb.h"
#include "Projectile.h"
#include <spdlog/spdlog.h>
#include "LogMacro.h"

using namespace PacketDef;

GameSystemUpdater::GameSystemUpdater(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem) { reqControllerContainer = make_unique<RequestControllerContainer>(gameSystem, dataSystem); }

void GameSystemUpdater::UpdateEachScene(float deltaTime, sptr<Scene>& scene)
{
	elapsedTime += deltaTime;

	vector<sptr<Player>> playersInScene = scene->GetAllPlayer();

	// Process request queue
	{
		ProcessRequestQueue(scene);
	}

	// SpawnManager Update
	{
		vector<sptr<TransformEntity>> readyToSpawn = scene->spawnManager->GetReadyToSpawn();

		vector<sptr<NPC>> vecSpawnedNpc;
		for (sptr<TransformEntity>& transformEntity : readyToSpawn)
		{
			scene->npcManager->AddNPC(transformEntity);

			sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
			if (npc == nullptr)
			{
				LOG_ERROR("TrnasformEntity is not NPC object");
				continue;
			}

			vecSpawnedNpc.push_back(npc);
		}

		SendNPCSpawnedToPlayer(scene, vecSpawnedNpc);
	}

	// NPC Update
	vector<sptr<TransformEntity>> vecNPC = scene->npcManager->getAllNpc();

	/*for (sptr<TransformEntity>& transformEntity : vecNPC)
	{
		sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
		if (npc == nullptr)
		{
			LOG_ERROR("Can not convert TransformEntity to NPC");
			continue;
		}
		UpdateEachNPC(deltaTime, scene, npc);
	}*/

	TimeUtil::LogElapsedTimeOnExceed("NPC Update", 0.033f,
		[&]() -> void
		{
			for (sptr<TransformEntity>& transformEntity : vecNPC)
			{
				sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
				if (npc == nullptr)
				{
					LOG_ERROR("Can not convert TransformEntity to NPC");
					continue;
				}
				UpdateEachNPC(deltaTime, scene, npc);
			}
		});

	// Player Update
	{
		for (sptr<Player>& player : playersInScene)
		{
			UpdateEachPlayer(deltaTime, scene, player);
		}
	}

	// Projectile Update
	vector<sptr<TransformEntity>> vecProjectile = scene->projectileManager->getAllProjectile();
	{
		for (sptr<TransformEntity>& transformEntity : vecProjectile)
		{
			sptr<Projectile> projectile = dynamic_pointer_cast<Projectile>(transformEntity);
			if (projectile == nullptr)
			{
				LOG_ERROR("Can not convert TransformEntity to Proejctile");
				continue;
			}

			projectile->Update(deltaTime);
		}
	}

	// Sync position
	{
		if (elapsedTime - lastChecked > 2)
		{
			SyncNPCPosition(playersInScene, vecNPC);
			// SyncProjectilePosition(playersInScene, vecProjectile);
			SyncPlayerPosition(playersInScene);

			lastChecked = elapsedTime;
		}
	}
}

void GameSystemUpdater::UpdateEachPlayer(float deltaTime, sptr<Scene>& scene, sptr<Player>& player)
{
	player->Update(deltaTime);

	Vector3 currentPosition = player->GetPosition();
	Vector3 newPosition = scene->navigationMeshAgent->ResolveCollision(currentPosition, player->GetRadius());
	player->SetPosition(newPosition);

	queue<TriggeredOperation> triggeredOperationQueue = player->skillController->GetReadyOperation();

	while (!triggeredOperationQueue.empty())
	{
		TriggeredOperation& triggeredOperation = triggeredOperationQueue.front();
		operationProcessController->ProcessOperation(scene, triggeredOperation);

		triggeredOperationQueue.pop();
	}
}

void GameSystemUpdater::UpdateEachNPC(float deltaTime, sptr<Scene>& scene, sptr<NPC>& npc)
{
	npc->Update(deltaTime);

	if (npc->patrolController->NeedToSwitchMoveDirection())
	{
		npc->patrolController->SwitchToNextMoveDirection();
		Vector3 newMoveDirection = npc->patrolController->GetCurrentMoveDirection();
		npc->SetMoveDirection(newMoveDirection);
	}

	Vector3 currentPosition = npc->GetPosition();
	Vector3 newPosition = scene->navigationMeshAgent->ResolveCollision(currentPosition, npc->GetRadius());
	npc->SetPosition(newPosition);
	//npc->SetPosition(newPosition);
}

void GameSystemUpdater::ProcessRequestQueue(sptr<Scene>& scene)
{
	queue<sptr<Request>> copied = scene->FlushQueue();
	while (!copied.empty())
	{
		sptr<Request> request = copied.front();

		sptr<IRequestController> controller = reqControllerContainer->GetController(request->GetRequestGroupId());
		if (controller)
		{
			controller->Process(request);
		}
		else
		{
			LOG_ERROR("GameSystemControllerContainer has no controller for GroupId = " + request->GetRequestGroupId());
		}
		copied.pop();
	}
}

void GameSystemUpdater::SendNPCSpawnedToPlayer(sptr<Scene>& scene, vector<sptr<NPC>>& vecNpc)
{
	/*PhysicsEngine::Vector3 position = npc->GetPosition();

	Protocol::NPCSpawned npcSpawned;
	npcSpawned.mutable_position()->set_x(position.x);
	npcSpawned.mutable_position()->set_y(position.y);
	npcSpawned.mutable_position()->set_z(position.z);

	npcSpawned.mutable_npcinfo()->set_npcid(npc->npcId);
	npcSpawned.mutable_npcinfo()->set_npcindex(npc->npcIndex);
	npcSpawned.mutable_npcinfo()->set_npcname(npc->npcName);

	npcSpawned.mutable_statinfo()->set_maxhp(npc->GetStat(STAT_TYPE::MAX_HP));
	npcSpawned.mutable_statinfo()->set_maxmp(npc->GetStat(STAT_TYPE::MAX_MP));
	npcSpawned.mutable_statinfo()->set_armor(npc->GetStat(STAT_TYPE::ARMOR));
	npcSpawned.mutable_statinfo()->set_attackpower(npc->GetStat(STAT_TYPE::ATTACK_POWER));
	npcSpawned.mutable_statinfo()->set_attackspeed(npc->GetStat(STAT_TYPE::ATTACK_SPEED));
	npcSpawned.mutable_statinfo()->set_magicpower(npc->GetStat(STAT_TYPE::MAGIC_POWER));
	npcSpawned.mutable_statinfo()->set_magicresistance(npc->GetStat(STAT_TYPE::MAGIC_RESISTANCE));
	npcSpawned.mutable_statinfo()->set_movespeed(npc->GetStat(STAT_TYPE::MOVE_SPEED));

	Packet packet(REQ_GROUP_ID::GAME, REQ_ID_GAME::NPC_SPAWNED_LIST);
	packet.WriteData<Protocol::NPCSpawned>(npcSpawned);

	for (const sptr<Player>& player : players)
	{
					player->Send(packet);
	}*/
}

void GameSystemUpdater::SyncPlayerPosition(vector<sptr<Player>>& players)
{
	for (sptr<Player>& from : players)
	{
		sptr<Packet> packetUpdatePosition = BuildPositionUpdatePacket(from);

		for (sptr<Player>& to : players)
		{
			to->Send(packetUpdatePosition);
		}
	}
}

void GameSystemUpdater::SyncNPCPosition(vector<sptr<Player>>& players, vector<sptr<TransformEntity>> npcs)
{
	if (players.size() == 0)
	{
		return;
	}

	for (sptr<TransformEntity>& from : npcs)
	{
		sptr<Packet> packetUpdatePosition = BuildPositionUpdatePacket(from);

		for (sptr<Player>& to : players)
		{
			to->Send(packetUpdatePosition);
		}
	}
}

void GameSystemUpdater::SyncProjectilePosition(vector<sptr<Player>>& players, vector<sptr<TransformEntity>> projectiles)
{
	for (sptr<TransformEntity>& projectile : projectiles)
	{
		sptr<Packet> packetUpdatePosition = BuildPositionUpdatePacket(projectile);

		for (sptr<Player>& to : players)
		{
			to->Send(packetUpdatePosition);
		}
	}
}

sptr<Packet> GameSystemUpdater::BuildPositionUpdatePacket(sptr<TransformEntity> transform)
{
	Vector3 position = transform->GetPosition();
	Vector3 moveDirection = transform->GetMoveDirection();

	Protocol::POSITION_UPDATE positionUpdate;
	positionUpdate.set_transformentityid(transform->GetEntityId());
	positionUpdate.set_transformentitytype(transform->GetEntityType());

	positionUpdate.mutable_position()->set_x(position.x);
	positionUpdate.mutable_position()->set_y(position.y);
	positionUpdate.mutable_position()->set_z(position.z);

	positionUpdate.mutable_movedirection()->set_x(moveDirection.x);
	positionUpdate.mutable_movedirection()->set_y(moveDirection.y);
	positionUpdate.mutable_movedirection()->set_z(moveDirection.z);

	sptr<Packet> packet = make_shared<Packet>(REQ_GROUP_ID::GAME, REQ_ID_GAME::POSITION_UPDATE);
	packet->WriteData<Protocol::POSITION_UPDATE>(positionUpdate);
	return packet;
}
