#pragma once
#include <string>
#include "GameSystemReq.h"
#include "PhysicsEngine.h"
#include "SpawnManager.h"
#include "NPCManager.h"
#include "ProjectileManager.h"
#include "Request.h"

using GameSystemReq::BaseReq;
using std::string;

class Scene
{
private:
	USE_LOCK;
	queue<sptr<Request>> requestQueue;
	std::set<int> setPlayer;

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

	std::set<int> GetPlayerIdsInScene() { return setPlayer; }
	void AddPlayerId(int playerId) { setPlayer.insert(playerId); }
};
