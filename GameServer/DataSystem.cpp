#include "pch.h"
#include "DataSystem.h"

DataSystem::DataSystem()
{
	navigationMeshAgentManager = make_unique<NavigationMeshAgentManager>();
	sceneInfoManager = make_unique<SceneInfoManager>();
	baseStatManager = make_unique<BaseStatManager>();
	skillInfoManager = make_unique<SkillInfoManager>();
	spawnInfoManager = make_unique<SpawnInfoManager>();
	npcInfoManager = make_unique<NPCInfoManager>();
	projectileInfoManager = make_unique<ProjectileInfoManager>();
}

void DataSystem::LoadJsonData()
{
	navigationMeshAgentManager->LoadJsonData();
	baseStatManager->LoadJsonData();
	sceneInfoManager->LoadJsonData();
	spawnInfoManager->LoadJsonData();
	npcInfoManager->LoadJsonData();
	skillInfoManager->LoadJsonData();
	projectileInfoManager->LoadJsonData();
}
