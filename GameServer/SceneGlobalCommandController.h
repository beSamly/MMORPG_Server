#pragma once
#include "CommandProcessCommon.h"
#include "ISceneCommandController.h"
#include "Command.h"
#include "GameSystem.h"

using Command::COMMAND_ID_SCENE_GLOBAL;
using SceneCommandProcessCommon::BaseCommandProcessFunc;

class SceneGlobalCommandController : public ISceneCommandController
{
private:
    sptr<Logger> logger;
    map<COMMAND_ID_SCENE_GLOBAL, BaseCommandProcessFunc> mapProcessFunc;

public:
    SceneGlobalCommandController(sptr<Logger> logger);
    virtual int Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<CommandBase>& command) override;

private:
    int ProcessEnterScene(GameSystem& gameSystem, sptr<Scene>& scene, sptr<CommandBase>& command);
};
