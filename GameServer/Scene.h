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

    map<int, sptr<Player>> mapPlayer;

public:
    string sceneName;
    Scene(string paramSceneName) : sceneName(paramSceneName) {}

    void PushCommand(sptr<BaseReq> command);
    queue<sptr<BaseReq>> FlushQueue();

    void Update(float deltaTime);
    void AddPlayer(sptr<Player> player) { mapPlayer[player->GetPlayerId()] = player; }
    sptr<Player> GetPlayer(int playerId);
};
