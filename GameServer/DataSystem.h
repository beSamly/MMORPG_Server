#pragma once
#include "NavigationMeshAgentManager.h"
#include "SceneInfoManager.h"
#include "BaseStatManager.h"
#include "SkillDataManager.h"

class DataSystem
{
public:
	uptr<NavigationMeshAgentManager> navigationMeshAgentManager;
	uptr<SceneInfoManager> sceneInfoManager;
	uptr<BaseStatManager> baseStatManager;
	uptr<SkillDataManager> skillDataManager;

public:
	DataSystem();
	void LoadJsonData();
};
