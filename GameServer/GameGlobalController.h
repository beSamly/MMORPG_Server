#pragma once
#include "CommandProcessCommon.h"
#include "IGameSystemController.h"
#include "GameSystemReq.h"
#include "GameSystem.h"

using GameSystemReq::REQ_ID_GLOBAL;
using GameSystemReqProcessCommon::BaseCommandProcessFunc;

class GameGlobalController : public IGameSystemController
{
private:
    sptr<GameSystem> gameSystem;
	map<REQ_ID_GLOBAL, BaseCommandProcessFunc> mapProcessFunc;

public:
	GameGlobalController(sptr<GameSystem> paramGameSystem);
	virtual int Process(sptr<Scene>& scene, sptr<BaseReq>& command) override;

private:
	int ProcessEnterScene(sptr<Scene>& scene, sptr<BaseReq>& command);
    int ProcessNPCListReq(sptr<Scene>& scene, sptr<BaseReq>& command);
};
