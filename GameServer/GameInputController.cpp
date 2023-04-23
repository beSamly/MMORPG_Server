#include "pch.h"
#include "Packet.h"
#include "PacketDef.h"
#include "GameInputController.h"
#include "GameSystem.h"
#include "Scene.h"
#include "ResponseCode.h"
#include <InputMovementRes.pb.h>

using GameSystemReq::InputMovementReq;
using GameSystemReq::REQ_ID_INPUT;
using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_INPUT;

GameInputController::GameInputController(sptr<GameSystem> paramGameSystem, sptr<Logger> paramLogger) : gameSystem(paramGameSystem), logger(paramLogger)
{
    // mapProcessFunc[REQ_ID_INPUT::MOVEMENT] = TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement);
    mapProcessFunc.emplace(REQ_ID_INPUT::MOVEMENT, TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement));
}

int GameInputController::Process(sptr<Scene>& scene, sptr<BaseReq>& command)
{
    REQ_ID_INPUT commandId = static_cast<REQ_ID_INPUT>(command->commandId);
    PlayerCommandProcessFunc func = mapProcessFunc[commandId];

    sptr<Player> player = gameSystem->playerManager->GetPlayer(command->playerId);
    if (player == nullptr)
    {
        // logger->Error("Player not found from scene for sceneName = {} playerId = {}", scene->sceneName, command->playerId);
        return RES_CODE::CODE_PLAYER_NOT_FOUND;
    }

    if (func)
    {
        return func(scene, player, command);
    }
    else
    {
        // logger->Error("GameGlobalController has no process function for commandId = {}", command->commandId);
        return RES_CODE::CODE_PROCESS_FUNC_NOT_FOUND;
    }
}

int GameInputController::ProcessInputMovement(sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command)
{
    sptr<InputMovementReq> inputMovementCommand;
    int result = [&]() -> int
    {
        inputMovementCommand = dynamic_pointer_cast<InputMovementReq>(command);
        if (inputMovementCommand == nullptr)
        {
            return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
        }

        player->inputController->SetKeyPressed(KEY_INPUT::UP, inputMovementCommand->up);
        player->inputController->SetKeyPressed(KEY_INPUT::DOWN, inputMovementCommand->down);
        player->inputController->SetKeyPressed(KEY_INPUT::LEFT, inputMovementCommand->left);
        player->inputController->SetKeyPressed(KEY_INPUT::RIGHT, inputMovementCommand->right);

        return RES_CODE::CODE_SUCCESS;
    }();

    Protocol::InputMovementRes res;
    res.set_result(result);
    Packet packet(PACKET_GROUP_ID::INPUT, PACKET_ID_INPUT::MOVEMENT);
    
    if (result == RES_CODE::CODE_SUCCESS)
    {
        res.set_up(inputMovementCommand->up);
        res.set_down(inputMovementCommand->down);
        res.set_left(inputMovementCommand->left);
        res.set_right(inputMovementCommand->right);
    }

    packet.WriteData<Protocol::InputMovementRes>(res);
    player->Send(packet.GetSendBuffer());
    return result;
}
