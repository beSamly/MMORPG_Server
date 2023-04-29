#pragma once
#include "Logger.h"
#include "GameSystemReq.h"
#include "IGameSystemController.h"
#include "CommandProcessCommon.h"

using GameSystemReq::REQ_ID_POSITION;
using GameSystemReqProcessCommon::PlayerCommandProcessFunc;

class GamePositionController : public IGameSystemController
{
private:
    sptr<GameSystem> gameSystem;
    map<REQ_ID_POSITION, function<int(sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command)>> mapProcessFunc;

public:
    GamePositionController(sptr<GameSystem> paramGameSystem);
    virtual int Process(sptr<Scene>& scene, sptr<BaseReq>& command) override;

private:
    int ProcessMoveReq(sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command);
};
