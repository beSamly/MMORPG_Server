#pragma once
#include "GameSystemReq.h"
#include "DataSystem.h"
#include "SceneManager.h"
#include "PlayerManager.h"
#include "GameSystemUpdater.h"
#include "ClientManager.h"

using GameSystemReq::BaseReq;

class GameSystemUpdater;

class GameSystem : public std::enable_shared_from_this<GameSystem>
{
public:
    GameSystem(sptr<DataSystem> p_dataSystem);

public:
    void UpdateScene(int threadId, float deltaTime);
    uptr<PlayerManager> playerManager;
    uptr<SceneManager> sceneManager;
    uptr<GameSystemUpdater> gameSystemUpdater;
    uptr<ClientManager> clientManager;

    void Init();

private:
    USE_LOCK;

    /* GameData related */
    sptr<DataSystem> dataSystem;

    /* Command related */

private:
    void InitSceneManager();
};
