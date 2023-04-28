#include "pch.h"
#include "DataSystem.h"

DataSystem::DataSystem()
{
	navigationMeshAgentManager = make_unique<NavigationMeshAgentManager>();
	sceneInfoManager = make_unique<SceneInfoManager>();
	baseStatManager = make_unique<BaseStatManager>();
	skillDataManager = make_unique<SkillDataManager>();
}

void DataSystem::LoadJsonData()
{
	navigationMeshAgentManager->LoadJsonData();
	baseStatManager->LoadJsonData();
    sceneInfoManager->LoadJsonData();
    //skillDataManager->LoadJsonData();
}
