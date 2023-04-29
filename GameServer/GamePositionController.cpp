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
using GameSystemReq::REQ_ID_POSITION;
using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_POSITION;

GamePositionController::GamePositionController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem)
{
    // mapProcessFunc[REQ_ID_POSITION::MOVEMENT] = TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement);
    mapProcessFunc.emplace(REQ_ID_POSITION::MOVE, TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessMoveReq));
}

int GamePositionController::Process(sptr<Scene>& scene, sptr<BaseReq>& command)
{
    REQ_ID_POSITION commandId = static_cast<REQ_ID_POSITION>(command->commandId);
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
    sptr<MoveReq> moveReq;
    int result = [&]() -> int
    {
        moveReq = dynamic_pointer_cast<MoveReq>(req);
        if (moveReq == nullptr)
        {
            return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
        }

        player->inputController->SetMoveDirection(moveReq->direction);
        return RES_CODE::CODE_SUCCESS;
    }();

    Protocol::MoveRes res;
    res.set_result(result);
    Packet packet(PACKET_GROUP_ID::POSITION, PACKET_ID_POSITION::MOVE_RES);
    
    if (result == RES_CODE::CODE_SUCCESS)
    {
        res.mutable_direction()->set_x(moveReq->direction.x);
        res.mutable_direction()->set_y(moveReq->direction.y);
        res.mutable_direction()->set_z(moveReq->direction.z);
    }

    packet.WriteData<Protocol::MoveRes>(res);
    player->Send(packet);
    return result;
}
