#pragma once
#include "GameSystemReq.h"
#include "DataSystem.h"
#include "SceneManager.h"
#include "PlayerManager.h"
#include "GameSystemReqControllerContainer.h"

using GameSystemReq::BaseReq;

class GameSystem
{
public:
    GameSystem(sptr<DataSystem> p_dataSystem);

public:
    void Update(float deltaTime);
    //void PushCommand(sptr<BaseReq> command);
    //void PushCommandToScene(int playerId, sptr<BaseReq> command);
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
    uptr<GameSystemReqControllerContainer> reqControllerContainer;

    /* GameData related */
    sptr<DataSystem> dataSystem;

    /* Command related */
};
