#pragma once
#include "Logger.h"
#include "GameSystemReq.h"
#include "IGameSystemController.h"
#include "CommandProcessCommon.h"

using SceneCommandProcessCommon::PlayerCommandProcessFunc;
using GameSystemReq::REQ_ID_INPUT;

class GameInputController : public IGameSystemController
{
private:
	sptr<Logger> logger;
	map<REQ_ID_INPUT, function<int(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command)>> mapProcessFunc;

public:
	GameInputController(sptr<Logger> logger);
	virtual int Process(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command) override;

private:
	int ProcessInputMovement(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command);
};
