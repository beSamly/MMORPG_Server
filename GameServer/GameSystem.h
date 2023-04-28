#pragma once
#include "GameSystemReq.h"
#include "DataSystem.h"
#include "SceneManager.h"
#include "PlayerManager.h"
#include "GameSystemControllerContainer.h"
#include "GameSystemUpdater.h"

using GameSystemReq::BaseReq;

class GameSystem : public std::enable_shared_from_this<GameSystem>
{
public:
    GameSystem(sptr<DataSystem> p_dataSystem);

public:
    void UpdateScene(int threadId, float deltaTime);
    uptr<PlayerManager> playerManager;
    uptr<SceneManager> sceneManager;
    uptr<GameSystemUpdater> gameSystemUpdater;

    void Init();

private:
    USE_LOCK;

    sptr<Logger> logger;

    /* Command related */
    uptr<GameSystemControllerContainer> reqControllerContainer;

    /* GameData related */
    sptr<DataSystem> dataSystem;

    /* Command related */

private:
    void InitSceneManager();
};
