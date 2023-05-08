#include "pch.h"
#include "DataSystem.h"

DataSystem::DataSystem()
{
	navigationMeshAgentManager = make_unique<NavigationMeshAgentManager>();
	sceneInfoManager = make_unique<SceneInfoManager>();
	baseStatManager = make_unique<BaseStatManager>();
	skillDataManager = make_unique<SkillDataManager>();
	spawnInfoManager = make_unique<SpawnInfoManager>();
	npcInfoManager = make_unique<NPCInfoManager>();
}

void DataSystem::LoadJsonData()
{
	//navigationMeshAgentManager->LoadJsonData();
	baseStatManager->LoadJsonData();
	sceneInfoManager->LoadJsonData();
	spawnInfoManager->LoadJsonData();
	npcInfoManager->LoadJsonData();
	skillDataManager->LoadJsonData();
}
