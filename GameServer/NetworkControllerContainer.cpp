#include "pch.h"
#include "NetworkControllerContainer.h"
#include "AuthController.h"
#include "PositionController.h"
#include "GLobalController.h"

using PacketDef::PACKET_GROUP_ID;

NetworkControllerContainer::NetworkControllerContainer(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem)
{
    sptr<AuthController> authController = make_shared<AuthController>(gameSystem, dataSystem);
    sptr<PositionController> positionController = make_shared<PositionController>(gameSystem);
    sptr<GlobalController> globalController = make_shared<GlobalController>(gameSystem);

    mapController.emplace(PACKET_GROUP_ID::AUTH, authController);
    mapController.emplace(PACKET_GROUP_ID::POSITION, positionController);
    mapController.emplace(PACKET_GROUP_ID::GLOBAL, globalController);
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
