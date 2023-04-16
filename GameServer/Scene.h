#pragma once
#include <string>
#include "Command.h"

using Command::CommandBase;
using std::string;

class Scene
{
private:
    USE_LOCK;
    queue<sptr<CommandBase>> commandQueue;

    map<int, sptr<Player>> mapPlayer;

public:
    string sceneName;
    Scene(string paramSceneName) : sceneName(paramSceneName) {}

    void PushCommand(sptr<CommandBase> command);
    queue<sptr<CommandBase>> FlushQueue();

    void Update(float deltaTime);
    void AddPlayer(sptr<Player> player) { mapPlayer[player->GetPlayerId()] = player; }
    sptr<Player> GetPlayer(int playerId);
};
