#pragma once
#include "DataSystem.h"
#include "SocketServer.h"
#include "GameSystem.h"
#include "NetworkControllerContainer.h"
#include "ClientManager.h"

class NetworkSystem
{
public:
    NetworkSystem(sptr<DataSystem> paramDataSystem, sptr<GameSystem> paramGameSystem);
    void StartSocketServer();
    void RunIoContext();

private:
    sptr<asio::io_context> context;
    sptr<DataSystem> dataSystem;
    sptr<GameSystem> gameSystem;
    sptr<SocketServer> socketServer;
    uptr<ClientManager> clientManager;

    sptr<NetworkControllerContainer> networkControllerContainer;

private:
    void OnClientAccept(sptr<AsioSession> client);
    void OnClientRecv(sptr<AsioSession> client, BYTE* buffer, int len);
    void OnClientDisconnect(sptr<AsioSession> client, std::error_code err);
};
