#pragma once
#include "Logger.h"
#include "GameSystemReq.h"
#include "IGameSystemController.h"
#include "CommandProcessCommon.h"

using GameSystemReq::REQ_ID_INPUT;
using GameSystemReqProcessCommon::PlayerCommandProcessFunc;

class GameInputController : public IGameSystemController
{
private:
    sptr<Logger> logger;
    sptr<GameSystem> gameSystem;
    map<REQ_ID_INPUT, function<int(sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command)>> mapProcessFunc;

public:
    GameInputController(sptr<GameSystem> paramGameSystem, sptr<Logger> logger);
    virtual int Process(sptr<Scene>& scene, sptr<BaseReq>& command) override;

private:
    int ProcessInputMovement(sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command);
};
