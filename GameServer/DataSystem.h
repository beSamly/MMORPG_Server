#pragma once
#include "NavigationMeshAgentManager.h"

class DataSystem
{
public:
    NavigationMeshAgentManager navigationMeshAgentManager;

public:
    DataSystem();
    void LoadJsonData();

};
