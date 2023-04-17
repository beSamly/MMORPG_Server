#include "pch.h"
#include "ServerApp.h"
#include "spdlog/spdlog.h"
#include "PacketHeader.h"
#include "TLS.h"
#include "GameSystem.h"

int MAX_WORKER_THREAD = 10;
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

void ServerApp::StartSocketServer()
{
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug

    networkSystem->StartSocketServer();

    for (int32 i = 0; i < MAX_WORKER_THREAD; i++)
    {
        threadSystem->Launch(
            [&]()
            {
                while (true)
                {
                    // LEndTickCount = ::GetTickCount64() + WORKER_TICK;

                    // 네트워크 입출력 및 패킷 핸들러 실행
                    //[TODO] 밖에 while문이 있을 필요가 있나?? RunIoContext 내부에서 while 돌 수도?? 아래 스트링에 디버거 걸어서 확인해보기 나중에
                    networkSystem->RunIoContext();
                    string debug = "come here???";
                }
            });
    }
}

void ServerApp::StartGameSystem()
{
    //게임시스템 쓰레드
    /*threadSystem->Launch(
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
                DWORD elapsedSec = elapsedMils / 1000;

                deltaTime = currentTime - prevTime;
                prevTime = currentTime;
                float deltaTimeInSec = elapsedMils / 1000;
                gameSystem->Update(deltaTimeInSec);
            }
        });*/

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