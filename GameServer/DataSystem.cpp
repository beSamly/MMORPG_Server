#include "pch.h"
#include "DataSystem.h"

DataSystem::DataSystem()
{
	navigationMeshAgentManager = make_shared<NavigationMeshAgentManager>();
	sceneInfoManager = make_shared<SceneInfoManager>();
	baseStatManager = make_shared<BaseStatManager>();
	spawnInfoManager = make_shared<SpawnInfoManager>();
	npcInfoManager = make_shared<NPCInfoManager>();
	skillInfoManager = make_shared<SkillInfoManager>();
	projectileInfoManager = make_shared<ProjectileInfoManager>();

	vecJsonDatamanager.push_back(navigationMeshAgentManager);
	vecJsonDatamanager.push_back(sceneInfoManager);
	vecJsonDatamanager.push_back(baseStatManager);
	vecJsonDatamanager.push_back(spawnInfoManager);
	vecJsonDatamanager.push_back(npcInfoManager);
	vecJsonDatamanager.push_back(skillInfoManager);
	vecJsonDatamanager.push_back(projectileInfoManager);

	skillFactory = make_unique<SkillFactory>(skillInfoManager, projectileInfoManager);
}

void DataSystem::LoadJsonData()
{
	for (sptr<JsonDataManager>& manager : vecJsonDatamanager) {
		manager->LoadJsonData();
	}
}
