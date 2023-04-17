#include "pch.h"
#include "GameSystem.h"
#include "GameSystemReqControllerContainer.h"
#include "SceneGlobalCommandController.h"

GameSystemReqControllerContainer::GameSystemReqControllerContainer(sptr<Logger> logger)
{
    sptr<SceneGlobalCommandController> sceneGlobalCommandController = make_shared<SceneGlobalCommandController>(logger);
    mapController.emplace(REQ_GROUP_ID::GLOBAL, sceneGlobalCommandController);
}

sptr<IGameSystemController> GameSystemReqControllerContainer::GetController(REQ_GROUP_ID groupId)
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
