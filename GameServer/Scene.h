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
	string sceneName;

public:
	Scene(string paramSceneName) : sceneName(paramSceneName) {}
	string GetSceneName() { return sceneName; }
	void SetSceneName(string name) { sceneName = name; }
	void PushCommand(sptr<BaseReq> command);
	queue<sptr<BaseReq>> FlushQueue();
	void Update(float deltaTime);

	set<int> GetAllPlayerId() { return setPlayer; }
	void AddPlayerId(int playerId) { setPlayer.insert(playerId); }
};
