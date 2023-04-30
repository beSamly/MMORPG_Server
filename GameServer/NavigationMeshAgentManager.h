#pragma once
#include "pch.h"
#include <PhysicsEngine.h>

class NavigationMeshAgentManager
{
private:
    map<string, sptr<PhysicsEngine::NavigationMeshAgent>> mapNavigationMeshAgent;

public:
    NavigationMeshAgentManager(){};
    void LoadJsonData();
    sptr<PhysicsEngine::NavigationMeshAgent> GetNavigationMeshAgent(string sceneName);

private:
    void LoadSceneData();
};
