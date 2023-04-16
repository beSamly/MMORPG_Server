#include "pch.h"
#include "GameSystemGlobalCommandController.h"
#include "Logger.h"
#include "GameSystem.h"

using namespace CommandResult;
using namespace Command;

GameSystemGlobalCommandController::GameSystemGlobalCommandController(sptr<Logger> paramLogger) : logger(paramLogger)
{
    mapProcessFunc[COMMAND_ID_GAME_SYSTEM_GLOBAL::PLAYER_LOG_IN] = TO_BASE_PROCESS_FUNC(ProcessPlayerLogIn);
}

int GameSystemGlobalCommandController::Process(GameSystem& gameSystem, sptr<CommandBase> command)
{
    COMMAND_ID_GAME_SYSTEM_GLOBAL commandId = static_cast<COMMAND_ID_GAME_SYSTEM_GLOBAL>(command->commandId);

    BaseCommandProcessFun func = mapProcessFunc[commandId];
    if (func)
    {
        return func(gameSystem, command);
    }
    else
    {
        logger->Error("GameSystemGlobalCommandController has no process function for commandId = {}",
                      command->commandId);
        return PROCESS_FUNC_NOT_FOUND;
    }
}

int GameSystemGlobalCommandController::ProcessPlayerLogIn(GameSystem& gameSystem, sptr<CommandBase>& command)
{
    sptr<CommandPlayerLogIn> commandLogIn = dynamic_pointer_cast<CommandPlayerLogIn>(command);
    if (commandLogIn == nullptr)
    {
        return COMMAND_TYPE_MISMATCH;
    }

    sptr<Scene> scene = gameSystem.sceneManager->GetScene(commandLogIn->sceneName);
    if (scene == nullptr)
    {
        logger->Error("ProcessPlayerLogIn - Scene not found for sceneName = {}", commandLogIn->sceneName);
        return SCENE_NOT_FOUND;
    }

    sptr<CommandEnterScene> commandEnterScene = make_shared<CommandEnterScene>();
    commandEnterScene->sceneName = commandLogIn->sceneName;
    commandEnterScene->player = commandLogIn->player;

    scene->PushCommand(commandEnterScene);
}
