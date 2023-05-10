#pragma once
#include "GameSystem.h"
#include "PacketDef.h"
#include "IRequestController.h"
#include "Logger.h"

using PacketDef::REQ_GROUP_ID;


class GameSystem;

class RequestControllerContainer
{
private:
	map<REQ_GROUP_ID, sptr<IRequestController>> mapController;

public:
	RequestControllerContainer(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem);
	sptr<IRequestController> GetController(int packetGroupId);
};
