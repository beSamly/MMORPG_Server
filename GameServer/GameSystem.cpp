#include "pch.h"
#include "GameSystem.h"
#include "DataSystem.h"
#include "GameSystemReq.h"
#include "ProxyManager.h"
#include "Packet.h"
#include "PlayerManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Logger.h"

DWORD intervalTick = 1000; // 3초에 한 번씩

GameSystem::GameSystem(sptr<DataSystem> p_dataSystem) : dataSystem(p_dataSystem)
{
    playerManager = make_unique<PlayerManager>();
    sceneManager = make_unique<SceneManager>();
    logger = make_shared<Logger>("dummy path");
    logger = make_shared<Logger>("dummy path");
    reqControllerContainer = make_unique<GameSystemReqControllerContainer>(logger);
}

void GameSystem::Update(float deltaTime)
{
    // GameSystem이 처리해야할 패킷 먼저 처리
}

//void GameSystem::PushCommand(sptr<BaseReq> command)
//{
//    WRITE_LOCK;
//    commandQueue.push(command);
//}
//
//void GameSystem::PushCommandToScene(int playerId, sptr<BaseReq> command)
//{
//
//    sptr<Scene> scene = GetSceneByPlayerId(playerId);
//    if (scene == nullptr)
//    {
//        logger->Error("Scene not found for playerId = {}", playerId);
//        return;
//    }
//
//    scene->PushCommand(command);
//}

sptr<Scene> GameSystem::GetSceneByPlayerId(int playerId)
{
    map<int, string>::iterator iter = mapPlayerIdSceneName.find(playerId);

    if (iter == mapPlayerIdSceneName.end())
    {
        return nullptr;
    }

    string& sceneName = iter->second;
    return sceneManager->GetScene(sceneName);
}

void GameSystem::UpdateScene(int threadId, float deltaTime)
{
    // Scene 몇개 찾아서
    // loop 돌면서
    //  scene->flushqueue()
    //  GameSystemReqControllerContainer->process(command) 느낌으로 갈까?

    for (auto& [sceneName, scene] : *sceneManager->GetAllScene())
    {
        // 커맨드 먼저 처리
        queue<sptr<BaseReq>> copied = scene->FlushQueue();
        while (!copied.empty())
        {
            sptr<BaseReq> command = copied.front();
            int commandId = command->GetCommandId();

            sptr<IGameSystemController> controller = reqControllerContainer->GetController(command->commandGroupId);
            if (controller)
            {
                controller->Process(*this, scene, command);
            }
            else
            {
                logger->Error("GameSystemReqControllerContainer has no controller for commandGroupId = {}", command->commandGroupId);
            }
            copied.pop();
        }

        //씬 업데이트
        scene->Update(deltaTime);
    };
}
