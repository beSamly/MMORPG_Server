#pragma once
#include "NavigationMeshAgentManager.h"
#include "SceneInfoManager.h"

class DataSystem
{
public:
    uptr<NavigationMeshAgentManager> navigationMeshAgentManager;
    uptr<SceneInfoManager> sceneInfoManager;

public:
    DataSystem();
    void LoadJsonData();
};
