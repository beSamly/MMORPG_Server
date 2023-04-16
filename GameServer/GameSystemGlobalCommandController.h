#pragma once
#include "IGameSystemCommandController.h"
#include "Command.h"
#include "GameSystem.h"
#include "CommandProcessCommon.h"

using Command::COMMAND_ID_GAME_SYSTEM_GLOBAL;
using GameSystemCommandProcessCommon::BaseCommandProcessFun;

class GameSystemGlobalCommandController : public IGameSystemCommandController
{

private:
    sptr<Logger> logger;
    map<COMMAND_ID_GAME_SYSTEM_GLOBAL, BaseCommandProcessFun> mapProcessFunc;

public:
    GameSystemGlobalCommandController(sptr<Logger> logger);
    virtual int Process(GameSystem& gameSystem, sptr<CommandBase> command) override;

private:
    int ProcessPlayerLogIn(GameSystem& gameSystem, sptr<CommandBase>& command);
};
