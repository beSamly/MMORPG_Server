#include "pch.h"
#include "GameController.h"
#include "ResponseCode.h"
#include <Packet.h>
#include "MOVE_REQ.pb.h"
#include "MOVE_RES.pb.h"
#include "NPC_LIST_RES.pb.h"
#include "ENTER_SCENE_RES.pb.h"
#include "USE_SKILL_REQ.pb.h"
#include "USE_SKILL_RES.pb.h"
#include "PacketDef.h"

GameController::GameController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem)
{
	AddProcessFunc(REQ_ID_GAME::MOVE_REQ, TO_REQUEST_PROCESS_FUNC(Process_MOVE_REQ));
	AddProcessFunc(REQ_ID_GAME::ENTER_SCENE_REQ, TO_REQUEST_PROCESS_FUNC(Process_ENTER_SCENE_REQ));
	AddProcessFunc(REQ_ID_GAME::USE_SKILL_REQ, TO_REQUEST_PROCESS_FUNC(Process_USE_SKILL_REQ));
}

int GameController::Process_MOVE_REQ(sptr<Request>& request)
{
	sptr<Player> player = request->player;
	Protocol::MOVE_REQ pkt;
	Vector3 direction;

	int result = [&]() -> int
	{
		if (request->packet->ExtractData<Protocol::MOVE_REQ>(pkt) == false)
		{
			return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;
		}

		sptr<Scene> scene = gameSystem->sceneManager->GetScene(player->currentSceneName);
		if (scene == nullptr)
		{
			return RES_CODE::CODE_SCENE_NOT_FOUND;
		}

		direction.x = pkt.direction().x();
		direction.y = pkt.direction().y();
		direction.z = pkt.direction().z();
		player->SetMoveDirection(direction);

		return RES_CODE::CODE_SUCCESS;
	}();

	Protocol::MOVE_RES res;
	res.set_result(result);
	Packet packet(REQ_GROUP_ID::GAME, REQ_ID_GAME::MOVE_RES);

	//[TODO] 성공일 경우 Scene의 모든 Player 에게 보내기
	if (result == RES_CODE::CODE_SUCCESS)
	{
		res.mutable_direction()->set_x(direction.x);
		res.mutable_direction()->set_y(direction.y);
		res.mutable_direction()->set_z(direction.z);
	}

	packet.WriteData<Protocol::MOVE_RES>(res);
	player->Send(packet);
	return result;
}

int GameController::Process_NPC_LIST_REQ(sptr<Request>& request)
{
	sptr<Player> player = request->player;

	int result = [&]() -> int
	{
		sptr<Scene> scene = gameSystem->sceneManager->GetScene(player->currentSceneName);
		if (scene == nullptr)
		{
			return RES_CODE::CODE_SCENE_NOT_FOUND;
		}

		// Version 1 - 한꺼번에 모아서 보내주기
		{
			Protocol::NPC_LIST_RES npcListRes;
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

				Protocol::NPC_INFO* npcInfo = npcListRes.add_npcinfo();
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

			Packet pakcet(REQ_GROUP_ID::GAME, REQ_ID_GAME::NPC_LIST_RES);
			pakcet.WriteData<Protocol::NPC_LIST_RES>(npcListRes);
			player->Send(pakcet);
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

					Protocol::NPC_LIST_RES npcListRes;

					PhysicsEngine::Vector3 position = transformEntity->GetPosition();

					Protocol::NPC_INFO* npcInfo = npcListRes.add_npcinfo();
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
					pakcet.WriteData<Protocol::NPC_LIST_RES>(npcListRes);
					player->Send(pakcet);
			}*/
		}
		return RES_CODE::CODE_SUCCESS;
	}();

	return result;
}

int GameController::Process_ENTER_SCENE_REQ(sptr<Request>& request)
{
	int result = [&]() -> int
	{
		sptr<Player> player = request->player;
		sptr<Scene> scene = gameSystem->sceneManager->GetScene(player->currentSceneName);
		if (scene == nullptr)
		{
			return RES_CODE::CODE_SCENE_NOT_FOUND;
		}

		//기둥 충돌 테스트
		float x = 414.779f;
		float y = 113.919f;
		float z = 143.360f;

		player->SetPosition(Vector3(x, y, z));
		scene->AddPlayer(player);

		//씬에 접속 완료했다면 클라에게 보내준다
		Protocol::ENTER_SCENE_RES pkt;
		pkt.set_result(RES_CODE::CODE_SUCCESS);
		pkt.set_scenename("Main");
		pkt.mutable_position()->set_x(x);
		// pkt.mutable_position()->set_y(117.0f); // 공중
		pkt.mutable_position()->set_y(y);
		pkt.mutable_position()->set_z(z);

		Packet packet(REQ_GROUP_ID::GAME, REQ_ID_GAME::ENTER_SCENE_RES);
		packet.WriteData<Protocol::ENTER_SCENE_RES>(pkt);
		player->Send(packet);

		return RES_CODE::CODE_SUCCESS;
	}();

	return result;
}

int GameController::Process_USE_SKILL_REQ(sptr<Request>& request)
{
	Protocol::USE_SKILL_REQ reqPacket;
	sptr<Player> player = request->player;

	int result = [&]() -> int
	{
		if (request->packet->ExtractData<Protocol::USE_SKILL_REQ>(reqPacket) == false)
		{
			return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;
		}

		int skillIndex = reqPacket.skillindex();
		if (player->skillController->HasSkill(skillIndex))
		{
			return RES_CODE::CODE_PLAYER_DOES_NOT_HAVE_SKILL;
		}

		if (player->skillController->IsUsingSkill())
		{
			return RES_CODE::CODE_PLAYER_ALREADY_USING_SKILL;
		}

		PlayerInput playerInput;
		playerInput.direction.x = reqPacket.direction().x();
		playerInput.direction.y = reqPacket.direction().y();
		playerInput.direction.z = reqPacket.direction().z();

		player->skillController->UseSkill(skillIndex, playerInput);

		return RES_CODE::CODE_SUCCESS;
	}();


	Protocol::USE_SKILL_RES resPacket;
	resPacket.set_result(result);

	Packet packet(REQ_GROUP_ID::GAME, REQ_ID_GAME::USE_SKILL_RES);
	packet.WriteData<Protocol::USE_SKILL_RES>(resPacket);
	player->Send(packet);

	return result;
}
