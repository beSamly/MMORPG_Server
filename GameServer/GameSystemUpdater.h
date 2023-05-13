#pragma once
#include "Player.h"
#include "Scene.h"
#include "NPC.h"
#include "RequestControllerContainer.h"
#include "OperationProcessController.h"

class GameSystem;
class RequestControllerContainer;

class GameSystemUpdater
{
private:
    float lastChecked = 0.0f;
    float elapsedTime = 0.0f;

    uptr<RequestControllerContainer> reqControllerContainer;
    uptr<OperationProcessController> operationProcessController;

public:
    GameSystemUpdater(sptr<GameSystem> gameSystem, sptr<DataSystem> dataSystem);
    void UpdateEachScene(float deltaTime, sptr<Scene>& scene);
    void UpdateEachPlayer(float deltaTime, sptr<Scene>& scene, sptr<Player>& player);
    void UpdateEachNPC(float deltaTime, sptr<Scene>& scene, sptr<NPC>& npc);

private:
    void ProcessRequestQueue(sptr<Scene>& scene);
    void SendNPCSpawnedToPlayer(sptr<Scene>& scene, vector<sptr<NPC>>& vecNpc);

    void SyncPlayerPosition(vector<sptr<Player>>& players);
    void SyncNPCPosition(vector<sptr<Player>>& players, vector<sptr<TransformEntity>> npcs);
    void SyncProjectilePosition(vector<sptr<Player>>& players, vector<sptr<TransformEntity>> npcs);
    sptr<Packet> BuildPositionUpdatePacket(sptr<TransformEntity> transform);
};