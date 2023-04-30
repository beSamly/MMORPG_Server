#pragma once
#include "NavigationMeshAgentManager.h"
#include "SceneInfoManager.h"
#include "BaseStatManager.h"
#include "SkillDataManager.h"
#include "SpawnInfoManager.h"
#include "NPCInfoManager.h"

class DataSystem
{
public:
	uptr<NavigationMeshAgentManager> navigationMeshAgentManager;
	uptr<SceneInfoManager> sceneInfoManager;
	uptr<BaseStatManager> baseStatManager;
	uptr<SkillDataManager> skillDataManager;
	uptr<SpawnInfoManager> spawnInfoManager;
	uptr<NPCInfoManager> npcInfoManager;

public:
	DataSystem();
	void LoadJsonData();
};
