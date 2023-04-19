#include "pch.h"
#include "DataSystem.h"

DataSystem::DataSystem()
{
    navigationMeshAgentManager = make_unique<NavigationMeshAgentManager>();
    sceneInfoManager = make_unique<SceneInfoManager>();
}

void DataSystem::LoadJsonData()
{
    navigationMeshAgentManager->LoadJsonData();
    sceneInfoManager->LoadJsonData();
}
