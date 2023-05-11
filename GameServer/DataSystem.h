#pragma once
#include "NavigationMeshAgentManager.h"
#include "SceneInfoManager.h"
#include "BaseStatManager.h"
#include "SkillInfoManager.h"
#include "SpawnInfoManager.h"
#include "NPCInfoManager.h"
#include "ProjectileInfoManager.h"

class DataSystem
{
public:
	uptr<NavigationMeshAgentManager> navigationMeshAgentManager;
	uptr<SceneInfoManager> sceneInfoManager;
	uptr<BaseStatManager> baseStatManager;
	uptr<SkillInfoManager> skillInfoManager;
	uptr<SpawnInfoManager> spawnInfoManager;
	uptr<NPCInfoManager> npcInfoManager;
	uptr<ProjectileInfoManager> projectileInfoManager;

public:
	DataSystem();
	void LoadJsonData();
};
