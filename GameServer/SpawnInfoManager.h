#pragma once
#include "pch.h"
#include <PhysicsEngine.h>
#include "SpawnInfo.h"

class SpawnInfoManager
{
private:
    map<string, SpawnInfo> mapSpawnInfo;

public:
    SpawnInfoManager(){};
    void LoadJsonData();
    SpawnInfo GetSpawnInfo(string sceneName);
};
