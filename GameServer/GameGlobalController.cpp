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

	return RES_CODE::CODE_SUCCESS;
}

int GameGlobalController::ProcessNPCListReq(sptr<Scene>& scene, sptr<BaseReq>& command)
{
	return 0;
}
