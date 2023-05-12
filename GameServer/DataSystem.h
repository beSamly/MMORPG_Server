#pragma once
#include "NavigationMeshAgentManager.h"
#include "SceneInfoManager.h"
#include "BaseStatManager.h"
#include "SkillInfoManager.h"
#include "SpawnInfoManager.h"
#include "NPCInfoManager.h"
#include "ProjectileInfoManager.h"
#include "SkillFactory.h"

class DataSystem
{
public:
	sptr<NavigationMeshAgentManager> navigationMeshAgentManager;
	sptr<SceneInfoManager> sceneInfoManager;
	sptr<BaseStatManager> baseStatManager;
	sptr<SpawnInfoManager> spawnInfoManager;
	sptr<NPCInfoManager> npcInfoManager;
	sptr<SkillInfoManager> skillInfoManager;
	sptr<ProjectileInfoManager> projectileInfoManager;

	uptr<SkillFactory> skillFactory;

private:
	vector<sptr<JsonDataManager>> vecJsonDatamanager;

public:
	DataSystem();
	void LoadJsonData();

};
