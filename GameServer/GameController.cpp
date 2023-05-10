#include "pch.h"
#include "GameController.h"
#include "ResponseCode.h"
#include <Packet.h>
#include "InputMovementReq.pb.h"
#include "MoveReq.pb.h"
#include "MoveRes.pb.h"

GameController::GameController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem) {
	AddProcessFunc(REQ_ID_GAME::MOVE_REQ, TO_REQUEST_PROCESS_FUNC(ProcessMoveReq));
}


int GameController::ProcessMoveReq(sptr<Request>& request)
{
	sptr<Player> player = request->from;
	Protocol::MoveReq pkt;
	Vector3 direction;

	int result = [&]() -> int
	{
		if (request->packet->ExtractData<Protocol::MoveReq>(pkt) == false) {
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

	Protocol::MoveRes res;
	res.set_result(result);
	Packet packet(REQ_GROUP_ID::GAME, REQ_ID_GAME::MOVE_RES);

	//[TODO] 성공일 경우 Scene의 모든 Player 에게 보내기
	if (result == RES_CODE::CODE_SUCCESS)
	{
		res.mutable_direction()->set_x(direction.x);
		res.mutable_direction()->set_y(direction.y);
		res.mutable_direction()->set_z(direction.z);
	}

	packet.WriteData<Protocol::MoveRes>(res);
	player->Send(packet);
	return result;
}


int GameController::ProcessNPCListReq(sptr<Request>& request)
{
	//sptr<Player> player = request->from;

	//int result = [&]() -> int
	//{
	//	sptr<Scene> scene = gameSystem->sceneManager->GetScene(player->currentSceneName);
	//	if (scene == nullptr)
	//	{
	//		return RES_CODE::CODE_SCENE_NOT_FOUND;
	//	}


	//	return RES_CODE::CODE_SUCCESS;
	//}();

	//sptr<NPCListReq> npcListReq = dynamic_pointer_cast<NPCListReq>(command);
	//if (npcListReq == nullptr)
	//{
	//	return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
	//}

	//sptr<Player> player = npcListReq->player;

	//// Version 1 - 한꺼번에 모아서 보내주기
	//{
	//	Protocol::NPCListRes npcListRes;
	//	vector<sptr<TransformEntity>> npcInScene = scene->npcManager->getAllNpc();
	//	for (sptr<TransformEntity>& transformEntity : npcInScene)
	//	{
	//		sptr<NPC> npc = dynamic_pointer_cast<NPC>(transformEntity);
	//		if (npc == nullptr)
	//		{
	//			LOG_ERROR("TrnasformEntity is not NPC object");
	//			continue;
	//		}

	//		PhysicsEngine::Vector3 position = transformEntity->GetPosition();

	//		Protocol::NPCInfo* npcInfo = npcListRes.add_npcinfo();
	//		npcInfo->mutable_position()->set_x(position.x);
	//		npcInfo->mutable_position()->set_y(position.y);
	//		npcInfo->mutable_position()->set_z(position.z);

	//		npcInfo->mutable_npcbaseinfo()->set_npcid(npc->npcId);
	//		npcInfo->mutable_npcbaseinfo()->set_npcindex(npc->npcIndex);
	//		npcInfo->mutable_npcbaseinfo()->set_npcname(npc->npcName);

	//		npcInfo->mutable_statinfo()->set_maxhp(npc->GetStat(STAT_TYPE::MAX_HP));
	//		npcInfo->mutable_statinfo()->set_maxmp(npc->GetStat(STAT_TYPE::MAX_MP));
	//		npcInfo->mutable_statinfo()->set_armor(npc->GetStat(STAT_TYPE::ARMOR));
	//		npcInfo->mutable_statinfo()->set_attackpower(npc->GetStat(STAT_TYPE::ATTACK_POWER));
	//		npcInfo->mutable_statinfo()->set_attackspeed(npc->GetStat(STAT_TYPE::ATTACK_SPEED));
	//		npcInfo->mutable_statinfo()->set_magicpower(npc->GetStat(STAT_TYPE::MAGIC_POWER));
	//		npcInfo->mutable_statinfo()->set_magicresistance(npc->GetStat(STAT_TYPE::MAGIC_RESISTANCE));
	//		npcInfo->mutable_statinfo()->set_movespeed(npc->GetStat(STAT_TYPE::MOVE_SPEED));
	//	}

	//	/*Packet pakcet(REQ_GROUP_ID::GLOBAL, REQ_ID_GLOBAL::NPC_LIST_RES);
	//	pakcet.WriteData<Protocol::NPCListRes>(npcListRes);
	//	player->Send(pakcet);*/
	//}

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

	return 0;
}

