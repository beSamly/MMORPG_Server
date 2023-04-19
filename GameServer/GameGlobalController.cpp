#include "pch.h"
#include "GameGlobalController.h"
#include "Logger.h"
#include "GameSystem.h"
#include "PacketDef.h"
#include <Packet.h>
#include "EnterSceneRes.pb.h"
#include "Vector3.pb.h"
#include <ResponseCode.h>

using GameSystemReq::EnterSceneReq;
using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_SCENE;

GameGlobalController::GameGlobalController(sptr<Logger> paramLogger) : logger(paramLogger)
{
	mapProcessFunc.emplace(REQ_ID_GLOBAL::ENTER_SCENE, TO_BASE_COMMAND_PROCESS_FUNC(ProcessEnterScene));

	//mapProcessFunc[COMMAND_ID_GAME_SYSTEM_GLOBAL::PLAYER_LOG_IN] = TO_BASE_COMMAND_PROCESS_FUNC(ProcessEnterScene);
}

int GameGlobalController::Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command)
{
	REQ_ID_GLOBAL commandId = static_cast<REQ_ID_GLOBAL>(command->commandId);
	BaseCommandProcessFunc func = mapProcessFunc[commandId];
	if (func)
	{
		return func(gameSystem, scene, command);
	}
	else
	{
		//logger->Error("GameGlobalController has no process function for commandId = {}", command->commandId);
		return RES_CODE::CODE_PROCESS_FUNC_NOT_FOUND;
	}
}

int GameGlobalController::ProcessEnterScene(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command)
{
	sptr<EnterSceneReq> enterSceneReq = dynamic_pointer_cast<EnterSceneReq>(command);
	if (enterSceneReq == nullptr)
	{
		return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
	}

	sptr<Player> player = enterSceneReq->player;

	gameSystem.playerManager->AddPlayer(player);
	player->SetCurrentSceneName(scene->GetSceneName());
	scene->AddPlayerId(player->GetPlayerId());

	//씬에 접속 완료했다면 클라에게 보내준다
	Protocol::EnterSceneRes pkt;
	pkt.set_result(true);
	pkt.set_scenename("Main");
	pkt.mutable_position()->set_x(0.0f);
	pkt.mutable_position()->set_y(0.0f);
	pkt.mutable_position()->set_z(0.0f);

	Packet packet(PACKET_GROUP_ID::SCENE, PACKET_ID_SCENE::ENTER_SCENE_RES);
	packet.WriteData<Protocol::EnterSceneRes>(pkt);

	player->Send(packet.GetSendBuffer());

	return RES_CODE::CODE_SUCCESS;
}
