#include "pch.h"
#include "SpawnManager.h"
#include "NPC.h"

SpawnManager::SpawnManager() {}

void SpawnManager::AddToSpawnQueue(sptr<TransformEntity> npc, int nextSpawnTime)
{
    NextSpawnTimeInfo nextSpawnTimeInfo;
    nextSpawnTimeInfo.nextSpawnTime = nextSpawnTime;
    nextSpawnTimeInfo.target = npc;

    spawnQueue.push(nextSpawnTimeInfo);
}

vector<sptr<TransformEntity>> SpawnManager::GetReadyToSpawn()
{
    vector<sptr<TransformEntity>> readyToSpawn;
    int currentTickCount = GetTickCount64();

    while (!spawnQueue.empty())
    {
        const NextSpawnTimeInfo& nextSpawnTimeInfo = spawnQueue.top();

        if (nextSpawnTimeInfo.nextSpawnTime <= currentTickCount)
        {
            readyToSpawn.push_back(nextSpawnTimeInfo.target);
            spawnQueue.pop();
        }
        else
        {
            break;
        }
    }

    return readyToSpawn;
}
