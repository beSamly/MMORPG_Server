#include "pch.h"
#include "GameSystem.h"
#include "GameSystemControllerContainer.h"
#include "GameGlobalController.h"

GameSystemControllerContainer::GameSystemControllerContainer(sptr<Logger> logger)
{
	sptr<GameGlobalController> sceneGlobalCommandController = make_shared<GameGlobalController>(logger);
	mapController.emplace(REQ_GROUP_ID::GLOBAL, sceneGlobalCommandController);
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
