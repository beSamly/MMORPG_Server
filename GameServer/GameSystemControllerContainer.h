#pragma once
#include "GameSystemReq.h"
#include "IGameSystemController.h"
#include "Logger.h"

using GameSystemReq::REQ_GROUP_ID;

class GameSystemControllerContainer
{
private:
	map<REQ_GROUP_ID, sptr<IGameSystemController>> mapController;

public:
	GameSystemControllerContainer(sptr<Logger> logger);
	sptr<IGameSystemController> GetController(REQ_GROUP_ID packetGroupId);
};
