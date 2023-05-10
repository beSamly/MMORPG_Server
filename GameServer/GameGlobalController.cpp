#include "pch.h"
#include "GameGlobalController.h"
#include "Logger.h"
#include "GameSystem.h"
#include "PacketDef.h"
#include <Packet.h>
#include "EnterSceneRes.pb.h"
#include "Vector3.pb.h"
#include <ResponseCode.h>
#include "GameSystemReq.h"
#include "NPCListRes.pb.h"
#include "NPCInfo.pb.h"
#include "NPCBaseInfo.pb.h"

using namespace GameSystemReq;

GameGlobalController::GameGlobalController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem)
{
	mapProcessFunc.emplace(GAME_REQ_ID_GLOBAL::ENTER_SCENE, TO_BASE_COMMAND_PROCESS_FUNC(ProcessEnterScene));
	mapProcessFunc.emplace(GAME_REQ_ID_GLOBAL::NPC_LIST_REQ, TO_BASE_COMMAND_PROCESS_FUNC(ProcessNPCListReq));

	// mapProcessFunc[COMMAND_ID_GAME_SYSTEM_GLOBAL::PLAYER_LOG_IN] = TO_BASE_COMMAND_PROCESS_FUNC(ProcessEnterScene);
}

int GameGlobalController::Process(sptr<Scene>& scene, sptr<BaseReq>& command)
{
	GAME_REQ_ID_GLOBAL commandId = static_cast<GAME_REQ_ID_GLOBAL>(command->commandId);
	BaseCommandProcessFunc func = mapProcessFunc[commandId];
	if (func)
	{
		return func(scene, command);
	}
	else
	{
		// LOG_ERROR("GameGlobalController has no process function for commandId = {}", command->commandId);
		return RES_CODE::CODE_PROCESS_FUNC_NOT_FOUND;
	}
}

int GameGlobalController::ProcessEnterScene(sptr<Scene>& scene, sptr<BaseReq>& command)
{
	sptr<EnterSceneReq> enterSceneReq = dynamic_pointer_cast<EnterSceneReq>(command);
	if (enterSceneReq == nullptr)
	{
		return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
	}

	sptr<Player> player = enterSceneReq->player;

	gameSystem->playerManager->AddPlayer(player);
	scene->AddPlayerId(player->playerId);

	// float x = 420.0f;
	//// float y = 117.0f; //공중
	// float y = 111.6f; //충돌
	// float z = 143.0f;

	//기둥 충돌 테스트
	float x = 414.779f;
	float y = 113.919f;
	float z = 143.360f;

	//씬에 접속 완료했다면 클라에게 보내준다
	Protocol::EnterSceneRes pkt;
	pkt.set_result(RES_CODE::CODE_SUCCESS);
	pkt.set_scenename("Main");
	pkt.mutable_position()->set_x(x);
	// pkt.mutable_position()->set_y(117.0f); // 공중
	pkt.mutable_position()->set_y(y);
	pkt.mutable_position()->set_z(z);

	Packet packet(GAME_REQ_GROUP_ID::GLOBAL, GAME_REQ_ID_GLOBAL::ENTER_SCENE);
	packet.WriteData<Protocol::EnterSceneRes>(pkt);
	player->Send(packet);

	player->SetPosition(Vector3(x, y, z));

	return RES_CODE::CODE_SUCCESS;
}

int GameGlobalController::ProcessNPCListReq(sptr<Scene>& scene, sptr<BaseReq>& command)
{
	sptr<NPCListReq> npcListReq = dynamic_pointer_cast<NPCListReq>(command);
	if (npcListReq == nullptr)
	{
		return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
	}

	sptr<Player> player = npcListReq->player;

	// Version 1 - 한꺼번에 모아서 보내주기
	{
		Protocol::NPCListRes npcListRes;
		vector<sptr<TransformEntity>> npcInScene = scene->npcManager->getAllNpc();
		for (sptr<TransformEntity>& transformEntity : npcInScene)
		{
			sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
			if (npc == nullptr)
			{
				LOG_ERROR("TrnasformEntity is not NPC object");
				continue;
			}

			PhysicsEngine::Vector3 position = transformEntity->GetPosition();

			Protocol::NPCInfo* npcInfo = npcListRes.add_npcinfo();
			npcInfo->mutable_position()->set_x(position.x);
			npcInfo->mutable_position()->set_y(position.y);
			npcInfo->mutable_position()->set_z(position.z);

			npcInfo->mutable_npcbaseinfo()->set_npcid(npc->npcId);
			npcInfo->mutable_npcbaseinfo()->set_npcindex(npc->npcIndex);
			npcInfo->mutable_npcbaseinfo()->set_npcname(npc->npcName);

			npcInfo->mutable_statinfo()->set_maxhp(npc->GetStat(STAT_TYPE::MAX_HP));
			npcInfo->mutable_statinfo()->set_maxmp(npc->GetStat(STAT_TYPE::MAX_MP));
			npcInfo->mutable_statinfo()->set_armor(npc->GetStat(STAT_TYPE::ARMOR));
			npcInfo->mutable_statinfo()->set_attackpower(npc->GetStat(STAT_TYPE::ATTACK_POWER));
			npcInfo->mutable_statinfo()->set_attackspeed(npc->GetStat(STAT_TYPE::ATTACK_SPEED));
			npcInfo->mutable_statinfo()->set_magicpower(npc->GetStat(STAT_TYPE::MAGIC_POWER));
			npcInfo->mutable_statinfo()->set_magicresistance(npc->GetStat(STAT_TYPE::MAGIC_RESISTANCE));
			npcInfo->mutable_statinfo()->set_movespeed(npc->GetStat(STAT_TYPE::MOVE_SPEED));
		}

		/*Packet pakcet(REQ_GROUP_ID::GLOBAL, REQ_ID_GLOBAL::NPC_LIST_RES);
		pakcet.WriteData<Protocol::NPCListRes>(npcListRes);
		player->Send(pakcet);*/
	}

	// Version 2 테스트용 - 하나하나 보내주기 동시에 많이 보내주면 클라에서 뭉태기로 받네 ;;
	{
		/*vector<sptr<TransformEntity>> npcInScene = scene->npcManager->getAllNpc();
		for (sptr<TransformEntity>& transformEntity : npcInScene)
		{
			sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
			if (npc == nullptr)
			{
				LOG_ERROR("TrnasformEntity is not NPC object");
				continue;
			}

			Protocol::NPCListRes npcListRes;

			PhysicsEngine::Vector3 position = transformEntity->GetPosition();

			Protocol::NPCInfo* npcInfo = npcListRes.add_npcinfo();
			npcInfo->mutable_position()->set_x(position.x);
			npcInfo->mutable_position()->set_y(position.y);
			npcInfo->mutable_position()->set_z(position.z);

			npcInfo->mutable_npcbaseinfo()->set_npcid(npc->npcId);
			npcInfo->mutable_npcbaseinfo()->set_npcindex(npc->npcIndex);
			npcInfo->mutable_npcbaseinfo()->set_npcname(npc->npcName);

			npcInfo->mutable_statinfo()->set_maxhp(npc->GetStat(STAT_TYPE::MAX_HP));
			npcInfo->mutable_statinfo()->set_maxmp(npc->GetStat(STAT_TYPE::MAX_MP));
			npcInfo->mutable_statinfo()->set_armor(npc->GetStat(STAT_TYPE::ARMOR));
			npcInfo->mutable_statinfo()->set_attackpower(npc->GetStat(STAT_TYPE::ATTACK_POWER));
			npcInfo->mutable_statinfo()->set_attackspeed(npc->GetStat(STAT_TYPE::ATTACK_SPEED));
			npcInfo->mutable_statinfo()->set_magicpower(npc->GetStat(STAT_TYPE::MAGIC_POWER));
			npcInfo->mutable_statinfo()->set_magicresistance(npc->GetStat(STAT_TYPE::MAGIC_RESISTANCE));
			npcInfo->mutable_statinfo()->set_movespeed(npc->GetStat(STAT_TYPE::MOVE_SPEED));

			Packet pakcet(REQ_GROUP_ID::GLOBAL, REQ_ID_GLOBAL::NPC_LIST_RES);
			pakcet.WriteData<Protocol::NPCListRes>(npcListRes);
			player->Send(pakcet);
		}*/
	}
}
