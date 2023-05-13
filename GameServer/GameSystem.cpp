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
#include "SceneInfo.h"
#include "GameSystemUpdater.h"
#include "NPC.h"

DWORD intervalTick = 1000; // 3초에 한 번씩

using PhysicsEngine::Vector3;

GameSystem::GameSystem(sptr<DataSystem> p_dataSystem) : dataSystem(p_dataSystem)
{
	playerManager = make_unique<PlayerManager>();
    clientManager = make_unique<ClientManager>();
	sceneManager = make_unique<SceneManager>();
}

void GameSystem::Init()
{
	gameSystemUpdater = make_unique<GameSystemUpdater>(shared_from_this(), dataSystem);
	InitSceneManager();
}

void GameSystem::InitSceneManager()
{
	vector<SceneInfo> vecSceneInfo = dataSystem->sceneInfoManager->GetAllSceneInfo();

	for (SceneInfo& sceneInfo : vecSceneInfo)
	{
		// 씬 객체 생성
		sptr<Scene> scene = make_shared<Scene>(sceneInfo.sceneName);

		// 씬의 네비게이션 매쉬 에이전트 객체 찾기
		sptr<PhysicsEngine::NavigationMeshAgent> navigationMeshAgent = dataSystem->navigationMeshAgentManager->GetNavigationMeshAgent(sceneInfo.sceneName);
		if (navigationMeshAgent == nullptr)
		{
			LOG_ERROR("NavigationMeshAgent not found for sceneName = " + sceneInfo.sceneName);
		}
		scene->navigationMeshAgent = navigationMeshAgent;

		// 씬의 SpawnManager 초기화
		SpawnInfo spawnInfo = dataSystem->spawnInfoManager->GetSpawnInfo(scene->sceneName);
		for (NPCSpawnInfo& npcSpawnInfo : spawnInfo.vecNPCSpawnInfo)
		{
			for (int i = 0; i < npcSpawnInfo.totalNumber; i++)
			{
				int spawnPointSize = npcSpawnInfo.vecSpawnPoint.size();
				PhysicsEngine::Vector3 spawnPoint = npcSpawnInfo.vecSpawnPoint[i % spawnPointSize];
				NPCInfo npcInfo = dataSystem->npcInfoManager->GetNPCInfo(npcSpawnInfo.npcIndex);
				BaseStatInfo baseStatInfo = dataSystem->baseStatManager->GetBaseStat(npcInfo.BaseStatIndex);

				sptr<NPC> npc = make_shared<NPC>();
				npc->npcIndex = npcSpawnInfo.npcIndex;
				npc->npcName = npcInfo.npcName;
				npc->npcId = (npc->npcIndex * 100000) + i; //[TODO] 나중에 수정
				npc->spawnCoolTime = npcSpawnInfo.spawnCoolTime;
				npc->SetPosition(spawnPoint);
				npc->statController->SetBaseStat(baseStatInfo);

				scene->spawnManager->AddToSpawnQueue(npc, GetTickCount64()); // 초기화 할 때는 바로 spawn 하기 위해 0 대입
			}
		}

		// 씬 매니저에 추가
		sceneManager->AddScene(scene);
	}
}

void GameSystem::UpdateScene(int threadId, float deltaTime)
{
	// LOG_DEBUG("[GameSystem] deltaTime = " + std::to_string(deltaTime));
	for (auto& [sceneName, scene] : *sceneManager->GetAllScene())
	{
		//씬 SpawnManager Update
		gameSystemUpdater->UpdateEachScene(deltaTime, scene);
	};
}
