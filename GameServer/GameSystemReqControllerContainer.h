#pragma once
#include "GameSystemReq.h"
#include "IGameSystemController.h"
#include "Logger.h"

using GameSystemReq::REQ_GROUP_ID;

class GameSystemReqControllerContainer
{
private:
    map<REQ_GROUP_ID, sptr<IGameSystemController>> mapController;

public:
    GameSystemReqControllerContainer(sptr<Logger> logger);
    sptr<IGameSystemController> GetController(REQ_GROUP_ID packetGroupId);
};
