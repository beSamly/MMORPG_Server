#include "pch.h"
#include "InputCommandController.h"
#include "GameSystem.h"
#include "Scene.h"

using Command::COMMAND_ID_INPUT;
using Command::CommandInputMovement;


InputCommandController::InputCommandController(sptr<Logger> paramLogger) : logger(paramLogger)
{
    //mapProcessFunc[COMMAND_ID_INPUT::MOVEMENT] = TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement);
    mapProcessFunc.emplace(COMMAND_ID_INPUT::MOVEMENT, TO_PLAYER_COMMAND_PROCESS_FUNC(ProcessInputMovement));
}

int InputCommandController::Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<CommandBase>& command)
{
    COMMAND_ID_INPUT commandId = static_cast<COMMAND_ID_INPUT>(command->commandId);
    PlayerCommandProcessFunc func = mapProcessFunc[commandId];

    sptr<Player> player = scene->GetPlayer(command->playerId);

    if (player == nullptr)
    {
        logger->Error("Player not found from scene for sceneName = {} playerId = {}", scene->sceneName, command->playerId);
        return CommandResult::PLAYER_NOT_FOUND;
    }

    if (func)
    {
        return func(gameSystem, scene, player, command);
    }
    else
    {
        logger->Error("SceneGlobalCommandController has no process function for commandId = {}", command->commandId);
        return CommandResult::PROCESS_FUNC_NOT_FOUND;
    }
}

int InputCommandController::ProcessInputMovement(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<CommandBase>& command)
{
    sptr<CommandInputMovement> inputMovementCommand = dynamic_pointer_cast<CommandInputMovement>(command);
    if (inputMovementCommand == nullptr)
    {
        return CommandResult::COMMAND_TYPE_MISMATCH;
    }

    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::UP, inputMovementCommand->up);
    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::DOWN, inputMovementCommand->down);
    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::LEFT, inputMovementCommand->left);
    player->GetController<InputController>()->HandleInputMovement(MOVEMENT_INPUT::RIGHT, inputMovementCommand->right);

    return CommandResult::COMMAND_RESULT_SUCCESS;
}
