#include "pch.h"
#include "GameSystem.h"
#include "GameSystemControllerContainer.h"
#include "GameGlobalController.h"
#include "GamePositionController.h"

GameSystemControllerContainer::GameSystemControllerContainer(sptr<GameSystem> gameSystem)
{
    sptr<GameGlobalController> globalController = make_shared<GameGlobalController>(gameSystem);
    sptr<GamePositionController> inputController = make_shared<GamePositionController>(gameSystem);

    mapController.emplace(REQ_GROUP_ID::GLOBAL, globalController);
    mapController.emplace(REQ_GROUP_ID::POSITION, inputController);
}

sptr<IGameSystemController> GameSystemControllerContainer::GetController(REQ_GROUP_ID groupId)
{
	if (mapController.count(groupId))
	{
		return mapController[groupId];
	}
	else
	{
		return nullptr;
	}
}
