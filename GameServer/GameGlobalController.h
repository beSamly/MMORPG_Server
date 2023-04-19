#pragma once
#include "CommandProcessCommon.h"
#include "IGameSystemController.h"
#include "GameSystemReq.h"
#include "GameSystem.h"

using GameSystemReq::REQ_ID_GLOBAL;
using SceneCommandProcessCommon::BaseCommandProcessFunc;

class GameGlobalController : public IGameSystemController
{
private:
	sptr<Logger> logger;
	map<REQ_ID_GLOBAL, BaseCommandProcessFunc> mapProcessFunc;

public:
	GameGlobalController(sptr<Logger> logger);
	virtual int Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command) override;

private:
	int ProcessEnterScene(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command);
};
