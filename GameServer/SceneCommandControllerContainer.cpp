#include "pch.h"
#include "GameSystem.h"
#include "SceneCommandControllerContainer.h"
#include "SceneGlobalCommandController.h"

SceneCommandControllerContainer::SceneCommandControllerContainer(sptr<Logger> logger)
{
    sptr<SceneGlobalCommandController> sceneGlobalCommandController = make_shared<SceneGlobalCommandController>(logger);
    mapController.emplace(COMMAND_GROUP_ID::SCENE_GLOBAL, sceneGlobalCommandController);
}

sptr<ISceneCommandController> SceneCommandControllerContainer::GetController(COMMAND_GROUP_ID groupId)
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
