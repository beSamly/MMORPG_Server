#pragma once
#include <string>
#include "GameSystemReq.h"
#include "PhysicsEngine.h"
#include "SpawnManager.h"
#include "NPCManager.h"
#include "ProjectileManager.h"
#include "Request.h"
#include "Player.h"
#include "Packet.h"

using GameSystemReq::BaseReq;
using std::string;

class Scene
{
private:
    USE_LOCK;
    queue<sptr<Request>> requestQueue;
    std::set<int> setPlayerId;
    map<int, sptr<Player>> mapPlayer;

public:
    string sceneName;
    sptr<PhysicsEngine::NavigationMeshAgent> navigationMeshAgent;
    uptr<SpawnManager> spawnManager;
    uptr<NPCManager> npcManager;
    uptr<ProjectileManager> projectileManager;

public:
    Scene(string paramSceneName);

    void PushRequest(sptr<Request> request);
    queue<sptr<Request>> FlushQueue();

    /*std::set<int> GetPlayerIdsInScene() { return setPlayerId; }
    void AddPlayerId(int playerId) { setPlayerId.insert(playerId); }*/

    void AddPlayer(sptr<Player>& player) { mapPlayer[player->playerId] = player; }
    void RemovePlayer(int playerId) { mapPlayer.erase(playerId); }
    vector<sptr<Player>> GetAllPlayer();
    void Broadcast(Packet& packet);
};
