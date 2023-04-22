#include "pch.h"
#include "ServerApp.h"
#include "spdlog/spdlog.h"
#include "PacketHeader.h"
#include "TLS.h"
#include "GameSystem.h"

int MAX_WORKER_THREAD = 1;
int MAX_SCENE_UPDATE_THREAD = 1;
int NETWORK_TIME_OUT_MS = 1000;
int WORKER_TICK = 64;

ServerApp::ServerApp()
{
	threadSystem = make_unique<ThreadSystem>();
	dataSystem = make_shared<DataSystem>();
	gameSystem = make_shared<GameSystem>(dataSystem);
	networkSystem = make_shared<NetworkSystem>(dataSystem, gameSystem);
}

void ServerApp::InitSystems() { 
	dataSystem->LoadJsonData();
    gameSystem->Init();

}

void ServerApp::StartSystems()
{
    StartSocketServer();
    StartGameSystem();
    JoinThread();
}

void ServerApp::StartSocketServer()
{
	spdlog::set_level(spdlog::level::debug); // Set global log level to debug

	networkSystem->StartSocketServer();

	for (int32 i = 0; i < MAX_WORKER_THREAD; i++)
	{
		threadSystem->Launch(
			[&]()
			{
				// 네트워크 입출력 및 패킷 핸들러 실행
				networkSystem->RunIoContext();
			});
	}
}

void ServerApp::InitGameSystem() {}

void ServerApp::StartGameSystem()
{
	// TODO 나중에 삭제하기
	// threadSystem->Launch(
	//    [&]()
	//    {
	//        while (true)
	//        {
	//            int keyPressed;
	//            debugInputHandler->PrintInstruction();
	//            std::cin >> keyPressed;
	//            debugInputHandler->HandleInput(keyPressed);
	//            // GInputHandler->HandleInput(socketClient, keyPressed);
	//            cout << "Key pressed is " << keyPressed << endl;
	//        }
	//    });

	//씬 업데이트 쓰레드
	for (int32 i = 0; i < MAX_SCENE_UPDATE_THREAD; i++)
	{
		threadSystem->Launch(
			[&]()
			{
				DWORD startTime = 0;
				DWORD deltaTime = 0;
				DWORD prevTime = 0;

				while (true)
				{
					DWORD currentTime = GetTickCount();
					if (startTime == 0)
					{
						startTime = currentTime;
					}

					DWORD elapsedMils = currentTime - startTime;

					deltaTime = currentTime - prevTime;
					prevTime = currentTime;
					float deltaTimeInSec = elapsedMils / 1000;
					gameSystem->UpdateScene(i, deltaTimeInSec);
				}
			});
	}
}