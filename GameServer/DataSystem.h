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
	uptr<NavigationMeshAgentManager> navigationMeshAgentManager;
	uptr<SceneInfoManager> sceneInfoManager;
	uptr<BaseStatManager> baseStatManager;
	uptr<SpawnInfoManager> spawnInfoManager;
	uptr<NPCInfoManager> npcInfoManager;
	sptr<SkillInfoManager> skillInfoManager;
	sptr<ProjectileInfoManager> projectileInfoManager;

	uptr<SkillFactory> skillFactory;

public:
	DataSystem();
	void LoadJsonData();

};
