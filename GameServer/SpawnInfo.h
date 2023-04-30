#pragma once
#include <string>
#include "PhysicsEngine.h"

struct NPCSpawnInfo
{
    int npcIndex;
    int spawnCoolTime;
    int totalNumber;
    std::vector<PhysicsEngine::Vector3> vecSpawnPoint;
};

struct SpawnInfo
{
    std::string sceneName;
    std::vector<NPCSpawnInfo> vecNPCSpawnInfo;

    SpawnInfo() {}
};
