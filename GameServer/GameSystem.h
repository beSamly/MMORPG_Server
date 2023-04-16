#pragma once
#include "Command.h"
#include "DataSystem.h"
#include "SceneManager.h"
#include "PlayerManager.h"
#include "SceneCommandControllerContainer.h"
#include "GameSystemCommandControllerContainer.h"

using Command::CommandBase;

class GameSystem
{
public:
    GameSystem(sptr<DataSystem> p_dataSystem);

public:
    void Update(float deltaTime);
    void PushCommand(sptr<CommandBase> command);
    void PushCommandToScene(int playerId, sptr<CommandBase> command);
    sptr<Scene> GetSceneByPlayerId(int playerId);

    void UpdateScene(int threadId, float deltaTime);
    uptr<PlayerManager> playerManager;
    uptr<SceneManager> sceneManager;

private:
    USE_LOCK;

    sptr<Logger> logger;
    map<int, string> mapPlayerIdSceneName;

    map<int, int> mapPlayerIdToMatchId;

    /* Command related */
    queue<sptr<CommandBase>> commandQueue;
    uptr<GameSystemCommandControllerContainer> gameSystemCommandControllerContainer;
    uptr<SceneCommandControllerContainer> sceneCommandControllerContainer;

    /* GameData related */
    sptr<DataSystem> dataSystem;

private:

    /* Command related */
    queue<sptr<CommandBase>> FlushQueue();
    void ProcessCommand();
};
