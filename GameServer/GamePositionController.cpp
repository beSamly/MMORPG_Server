#include "pch.h"
#include "Packet.h"
#include "PacketDef.h"
#include "GamePositionController.h"
#include "GameSystem.h"
#include "Scene.h"
#include "ResponseCode.h"
#include <InputMovementRes.pb.h>
#include "MoveRes.pb.h"

using GameSystemReq::MoveReq;
using GameSystemReq::GAME_REQ_ID_GAME;

GamePositionController::GamePositionController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem)
{
	// mapProcessFunc[GAME_REQ_ID_GAME::MOVEMENT] = TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement);
	mapProcessFunc.emplace(GAME_REQ_ID_GAME::MOVE, TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessMoveReq));
}

int GamePositionController::Process(sptr<Scene>& scene, sptr<BaseReq>& command)
{
	GAME_REQ_ID_GAME commandId = static_cast<GAME_REQ_ID_GAME>(command->commandId);
	PlayerCommandProcessFunc func = mapProcessFunc[commandId];

	sptr<Player> player = gameSystem->playerManager->GetPlayer(command->playerId);
	if (player == nullptr)
	{
		// LOG_ERROR("Player not found from scene for sceneName = {} playerId = {}", scene->sceneName, command->playerId);
		return RES_CODE::CODE_PLAYER_NOT_FOUND;
	}

	if (func)
	{
		return func(scene, player, command);
	}
	else
	{
		// LOG_ERROR("GameGlobalController has no process function for commandId = {}", command->commandId);
		return RES_CODE::CODE_PROCESS_FUNC_NOT_FOUND;
	}
}

int GamePositionController::ProcessMoveReq(sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& req)
{
	//sptr<MoveReq> moveReq;
	//int result = [&]() -> int
	//{
	//    moveReq = dynamic_pointer_cast<MoveReq>(req);
	//    if (moveReq == nullptr)
	//    {
	//        return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
	//    }

	//    player->SetMoveDirection(moveReq->direction);
	//    return RES_CODE::CODE_SUCCESS;
	//}();

	//Protocol::MoveRes res;
	//res.set_result(result);
	//Packet packet(REQ_GROUP_ID::GAME, GAME_REQ_ID_GAME::MOVE_RES);
	//
	////[TODO] 성공일 경우 Scene의 모든 Player 에게 보내기
	//if (result == RES_CODE::CODE_SUCCESS)
	//{
	//    res.mutable_direction()->set_x(moveReq->direction.x);
	//    res.mutable_direction()->set_y(moveReq->direction.y);
	//    res.mutable_direction()->set_z(moveReq->direction.z);
	//}

	//packet.WriteData<Protocol::MoveRes>(res);
	//player->Send(packet);
	//return result;

	return 1;
}
