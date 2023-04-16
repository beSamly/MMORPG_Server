#include "pch.h"
#include "GameSystem.h"
#include "GameSystemCommandControllerContainer.h"
#include "GameSystemGlobalCommandController.h"

GameSystemCommandControllerContainer::GameSystemCommandControllerContainer(sptr<Logger> logger)
{
    sptr<GameSystemGlobalCommandController> gameSystemGlobalCommandController = make_shared<GameSystemGlobalCommandController>(logger);
    mapController.emplace(COMMAND_GROUP_ID::GAME_SYSTEM_GLOBAL, gameSystemGlobalCommandController);
}

sptr<IGameSystemCommandController> GameSystemCommandControllerContainer::GetController(COMMAND_GROUP_ID groupId)
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
