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

DWORD intervalTick = 1000; // 3�ʿ� �� ����

GameSystem::GameSystem(sptr<DataSystem> p_dataSystem) : dataSystem(p_dataSystem)
{
	playerManager = make_unique<PlayerManager>();
	sceneManager = make_unique<SceneManager>();
	logger = make_shared<Logger>("dummy path");
	logger = make_shared<Logger>("dummy path");
	reqControllerContainer = make_unique<GameSystemControllerContainer>(logger);
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


void GameSystem::UpdateScene(int threadId, float deltaTime)
{
	// Scene � ã�Ƽ�
	// loop ���鼭
	//  scene->flushqueue()
	//  GameSystemControllerContainer->process(command) �������� ����?

	for (auto& [sceneName, scene] : *sceneManager->GetAllScene())
	{
		// Ŀ�ǵ� ���� ó��
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
				logger->Error("GameSystemControllerContainer has no controller for commandGroupId = " + command->commandGroupId);
			}
			copied.pop();
		}

		//���� Player ������Ʈ
		std::set<int> playerIds = scene->GetAllPlayerId();

		for (const int& playerId : playerIds) {

			sptr<Player> player = playerManager->GetPlayer(playerId);

			if (player == nullptr) {
				//!! ERROR
				continue;
			}

			player->Update(deltaTime);
		}
	};
}
