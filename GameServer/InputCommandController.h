#pragma once
#include "Logger.h"
#include "Command.h"
#include "ISceneCommandController.h"
#include "CommandProcessCommon.h"

using Command::COMMAND_ID_INPUT;
using SceneCommandProcessCommon::PlayerCommandProcessFunc;

class InputCommandController : public ISceneCommandController
{
private:
    sptr<Logger> logger;
    map<COMMAND_ID_INPUT, function<int(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<CommandBase>& command)>> mapProcessFunc;

public:
    InputCommandController(sptr<Logger> logger);
    virtual int Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<CommandBase>& command) override;

private:
    int ProcessInputMovement(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<CommandBase>& command);
};
