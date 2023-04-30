#pragma once
#include "pch.h"
#include "Player.h"
#include "Scene.h"
#include "GameSystemControllerContainer.h"
#include "NPC.h"

class GameSystemUpdater
{
private:
    float lastChecked = 0.0f;
    float elapsedTime = 0.0f;

    uptr<GameSystemControllerContainer> reqControllerContainer;

public:
    GameSystemUpdater(sptr<GameSystem> gameSystem);
    void UpdateEachScene(float deltaTime, sptr<Scene>& scene, vector<sptr<Player>>& playersInScene);
    void UpdateEachPlayer(float deltaTime, sptr<Scene>& scene, sptr<Player>& player, vector<sptr<Player>>& others);

private:
    void ProcessSceneReqQueue(sptr<Scene>& scene);
    void UpdateSpawnManager(sptr<Scene>& scene, vector<sptr<Player>>& players);
    void SendNPCSpawned(sptr<NPC>& npc, vector<sptr<Player>>& players);
    void UpdateNPC(float deltaTime, sptr<Scene>& scene);
};