#include "pch.h"
#include "NetworkControllerContainer.h"
#include "AuthController.h"
#include "InputReqController.h"

using PacketDef::PACKET_GROUP_ID;

NetworkControllerContainer::NetworkControllerContainer(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem, sptr<Logger> logger)
{
    sptr<AuthController> authController = make_shared<AuthController>(gameSystem, dataSystem, logger);
    sptr<InputReqController> inputReqController = make_shared<InputReqController>(gameSystem, logger);

    mapController.emplace(PACKET_GROUP_ID::AUTH, authController);
    mapController.emplace(PACKET_GROUP_ID::INPUT, inputReqController);
}

sptr<INetworkController> NetworkControllerContainer::GetController(int packetGroupId)
{
    PACKET_GROUP_ID groupId = static_cast<PACKET_GROUP_ID>(packetGroupId);
    if (mapController.count(groupId))
    {
        return mapController[groupId];
    }
    else
    {
        return nullptr;
    }
}
