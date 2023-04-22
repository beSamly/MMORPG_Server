#include "pch.h"
#include "DataSystem.h"

DataSystem::DataSystem()
{
    navigationMeshAgentManager = make_unique<NavigationMeshAgentManager>();
    sceneInfoManager = make_unique<SceneInfoManager>();
    baseStatManager = make_unique<BaseStatManager>();
}

void DataSystem::LoadJsonData()
{
    navigationMeshAgentManager->LoadJsonData();
    sceneInfoManager->LoadJsonData();
    baseStatManager->LoadJsonData();
}
