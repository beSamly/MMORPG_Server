#include "pch.h"
#include "GameSystemInputController.h"
#include "GameSystem.h"
#include "Scene.h"

using GameSystemReq::REQ_ID_INPUT;
using GameSystemReq::RESULT_TYPE;
using GameSystemReq::InputMovementReq;

GameSystemInputController::GameSystemInputController(sptr<Logger> paramLogger) : logger(paramLogger)
{
    //mapProcessFunc[REQ_ID_INPUT::MOVEMENT] = TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement);
    mapProcessFunc.emplace(REQ_ID_INPUT::MOVEMENT, TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement));
}

int GameSystemInputController::Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command)
{
    REQ_ID_INPUT commandId = static_cast<REQ_ID_INPUT>(command->commandId);
    PlayerCommandProcessFunc func = mapProcessFunc[commandId];

    sptr<Player> player = scene->GetPlayer(command->playerId);

    if (player == nullptr)
    {
        logger->Error("Player not found from scene for sceneName = {} playerId = {}", scene->sceneName, command->playerId);
        return RESULT_TYPE::PLAYER_NOT_FOUND;
    }

    if (func)
    {
        return func(gameSystem, scene, player, command);
    }
    else
    {
        logger->Error("SceneGlobalCommandController has no process function for commandId = {}", command->commandId);
        return RESULT_TYPE::PROCESS_FUNC_NOT_FOUND;
    }
}

int GameSystemInputController::ProcessInputMovement(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command)
{
    sptr<InputMovementReq> inputMovementCommand = dynamic_pointer_cast<InputMovementReq>(command);
    if (inputMovementCommand == nullptr)
    {
        return RESULT_TYPE::STRUCT_TYPE_MISMATCH;
    }

    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::UP, inputMovementCommand->up);
    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::DOWN, inputMovementCommand->down);
    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::LEFT, inputMovementCommand->left);
    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::RIGHT, inputMovementCommand->right);

    return RESULT_TYPE::SUCCESS;
}
