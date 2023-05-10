#pragma once
#include "GameSystemReq.h"
#include "IGameSystemController.h"
#include "Logger.h"

using GameSystemReq::GAME_REQ_GROUP_ID;

class GameSystemControllerContainer
{
private:
	map<GAME_REQ_GROUP_ID, sptr<IGameSystemController>> mapController;

public:
	GameSystemControllerContainer(sptr<GameSystem> gameSystem);
	sptr<IGameSystemController> GetController(GAME_REQ_GROUP_ID packetGroupId);
};
