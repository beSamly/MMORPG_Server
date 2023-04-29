#pragma once
#include "GameSystem.h"
#include "PacketDef.h"
#include "INetworkController.h"
#include "Logger.h"

using PacketDef::PACKET_GROUP_ID;

class NetworkControllerContainer
{
private:
    map<PACKET_GROUP_ID, sptr<INetworkController>> mapController;

public:
    NetworkControllerContainer(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem);
    sptr<INetworkController> GetController(int packetGroupId);
};
