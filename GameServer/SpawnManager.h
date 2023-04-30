#pragma once
#include "SpawnInfo.h"
#include "TransformEntity.h"

struct NextSpawnTimeInfo
{
    int nextSpawnTime;
    sptr<TransformEntity> target;

    bool operator<(const NextSpawnTimeInfo s) const { return this->nextSpawnTime > s.nextSpawnTime; }
};

class SpawnManager
{
private:
    std::priority_queue<NextSpawnTimeInfo> spawnQueue;

public:
    SpawnManager();
    void AddToSpawnQueue(sptr<TransformEntity> npc, int nextSpawnTime);
    vector<sptr<TransformEntity>> GetReadyToSpawn();
};
