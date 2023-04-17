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

                    // ��Ʈ��ũ ����� �� ��Ŷ �ڵ鷯 ����
                    //[TODO] �ۿ� while���� ���� �ʿ䰡 �ֳ�?? RunIoContext ���ο��� while �� ����?? �Ʒ� ��Ʈ���� ����� �ɾ Ȯ���غ��� ���߿�
                    networkSystem->RunIoContext();
                    string debug = "come here???";
                }
            });
    }
}

void ServerApp::StartGameSystem()
{
    //���ӽý��� ������
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

    // TODO ���߿� �����ϱ�
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

    //�� ������Ʈ ������
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