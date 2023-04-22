#pragma once
#include "NavigationMeshAgentManager.h"
#include "SceneInfoManager.h"
#include "BaseStatManager.h"

class DataSystem
{
public:
    uptr<NavigationMeshAgentManager> navigationMeshAgentManager;
    uptr<SceneInfoManager> sceneInfoManager;
    uptr<BaseStatManager> baseStatManager;

public:
    DataSystem();
    void LoadJsonData();
};
