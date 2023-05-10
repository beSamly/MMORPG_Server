#include "pch.h"
#include "RequestControllerContainer.h"
#include "AuthController.h"
#include "GameController.h"

using PacketDef::REQ_GROUP_ID;

RequestControllerContainer::RequestControllerContainer(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem)
{
	sptr<AuthController> authController = make_shared<AuthController>(gameSystem, dataSystem);
	sptr<GameController> gameController = make_shared<GameController>(gameSystem);

	mapController.emplace(REQ_GROUP_ID::AUTH, authController);
	mapController.emplace(REQ_GROUP_ID::GAME, gameController);
}

sptr<IRequestController> RequestControllerContainer::GetController(int packetGroupId)
{
	REQ_GROUP_ID groupId = static_cast<REQ_GROUP_ID>(packetGroupId);
	if (mapController.count(groupId))
	{
		return mapController[groupId];
	}
	else
	{
		return nullptr;
	}
}
