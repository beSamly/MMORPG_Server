#include "pch.h"
#include "DataSystem.h"

DataSystem::DataSystem()
{
	navigationMeshAgentManager = make_unique<NavigationMeshAgentManager>();
	sceneInfoManager = make_unique<SceneInfoManager>();
	baseStatManager = make_unique<BaseStatManager>();
	spawnInfoManager = make_unique<SpawnInfoManager>();
	npcInfoManager = make_unique<NPCInfoManager>();
	skillInfoManager = make_shared<SkillInfoManager>();
	projectileInfoManager = make_shared<ProjectileInfoManager>();

	skillFactory = make_unique<SkillFactory>(skillInfoManager, projectileInfoManager);
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
