#pragma once
#include <string>
#include "GameSystemReq.h"

using GameSystemReq::BaseReq;
using std::string;

class Scene
{
private:
	USE_LOCK;
	queue<sptr<BaseReq>> commandQueue;
	std::set<int> setPlayer;

public:
	string sceneName;
    sptr<PhysicsEngine::NavigationMeshAgent> navigationMeshAgent;

public:
	Scene(string paramSceneName) : sceneName(paramSceneName) {}

	void PushCommand(sptr<BaseReq> command);
	queue<sptr<BaseReq>> FlushQueue();
	void Update(float deltaTime);

	std::set<int> GetAllPlayerId() { return setPlayer; }
	void AddPlayerId(int playerId) { setPlayer.insert(playerId); }
};
