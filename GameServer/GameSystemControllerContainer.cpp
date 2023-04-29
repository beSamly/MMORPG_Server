#include "pch.h"
#include "GameSystem.h"
#include "GameSystemControllerContainer.h"
#include "GameGlobalController.h"
#include "GameInputController.h"

GameSystemControllerContainer::GameSystemControllerContainer(sptr<GameSystem> gameSystem)
{
    sptr<GameGlobalController> globalController = make_shared<GameGlobalController>(gameSystem);
    sptr<GameInputController> inputController = make_shared<GameInputController>(gameSystem);

    mapController.emplace(REQ_GROUP_ID::GLOBAL, globalController);
    mapController.emplace(REQ_GROUP_ID::INPUT, inputController);
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
