#include "pch.h"
#include "NetworkSystem.h"
#include "spdlog/spdlog.h"
#include "Packet.h"
#include "Logger.h"
#include "Player.h"
#include "PacketDef.h"


using namespace PacketDef;

namespace
{
    int32 PORT = 5000;
    int32 MAX_SESSION_COUNT = 100;
} // namespace

NetworkSystem::NetworkSystem(sptr<DataSystem> paramDataSystem, sptr<GameSystem> paramGameSystem) : dataSystem(paramDataSystem), gameSystem(paramGameSystem)
{
    context = make_shared<asio::io_context>();
    socketServer = make_shared<SocketServer>(context, PORT);
    // logger = make_shared<Logger>("Dummy file path");
}

void NetworkSystem::StartSocketServer()
{
    // 소켓 서버 실행
    socketServer->SetOnAcceptCallback([&](sptr<AsioSession> client) { OnClientAccept(client); });
    socketServer->SetOnClientRecv([&](sptr<AsioSession> client, BYTE* buffer, int len) { OnClientRecv(client, buffer, len); });
    socketServer->SetOnClientDisconnect([&](sptr<AsioSession> client, std::error_code err) { OnClientDisconnect(client, err); });
    // socketServer->setonclien OnClientConnect = [&](sptr<ClientSession> client) { OnClientConnect(client); };
    socketServer->StartAccept();

    spdlog::info("Server listening on {}", PORT);
}

void NetworkSystem::RunIoContext() { socketServer->RunIoContext(); }

void NetworkSystem::OnClientAccept(sptr<AsioSession> client)
{
    spdlog::debug("[NetworkSystem] Client connected");

    std::shared_ptr<ClientSession> clientSession = dynamic_pointer_cast<ClientSession>(client);
    if (!clientSession)
    {
        LOG_ERROR("[NetworkSystem] can not convert AsioSession to ClientSession");
        return;
    }

    gameSystem->clientManager->AddClient(clientSession);
    return;
}

void NetworkSystem::OnClientRecv(sptr<AsioSession> client, BYTE* buffer, int len)
{
    sptr<ClientSession> clientSession = dynamic_pointer_cast<ClientSession>(client);

    if (!clientSession)
    {
        LOG_ERROR("Can not convert AsioSession to ClientSession");
        return;
    }

    PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
    sptr<Packet> recvPacket = make_shared<Packet>(header->groupId, header->id);
    recvPacket->CopyData(buffer, len);

    sptr<Player> player = gameSystem->playerManager->GetPlayer(clientSession->playerId);

    sptr<Request> request = make_shared<Request>();
    request->session = clientSession;
    request->packet = recvPacket;
    request->player = player;

    sptr<Scene> mainScene = gameSystem->sceneManager->GetScene("Main");
    mainScene->PushRequest(request);

    // [TODO] GameSystem 큐에 넘기기
    /*sptr<IRequestController> controller = RequestControllerContainer->GetController(recvPacket.GetGroupId());
    if (controller)
    {
            controller->Process(clientSession, buffer, len);
    }
    else
    {
            LOG_ERROR("RequestControllerContainer has no controller for groupId = " + recvPacket.GetGroupId());
    }*/

    // if (clientSession->isAuthenticated)
    //{
    //     playerPacketController->HandleClientPacket(clientSession, buffer, len);
    // }
    // else
    //{
    //     clientPacketController->HandleClientPacket(clientSession, buffer, len);
    // }
}

void NetworkSystem::OnClientDisconnect(sptr<AsioSession> client, std::error_code err)
{
    LOG_INFO("[NetworkSystem] Client disconnected error_cde = " + std::to_string(err.value()));
    // LOG_INFO("[NetworkSystem] Client disconnected error_cde = " + std::to_string(err.value()));

    sptr<ClientSession> clientSession = dynamic_pointer_cast<ClientSession>(client);
    if (!clientSession)
    {
        LOG_ERROR("[NetworkSystem] can not convert AsioSession to ClientSession");
        return;
    }


    sptr<Packet> packet = make_shared<Packet>(REQ_GROUP_ID::AUTH, REQ_ID_AUTH::CLIENT_DISCONNECTED);

    sptr<Request> request = make_shared<Request>();
    request->session = clientSession;
    request->packet = packet;

    sptr<Scene> mainScene = gameSystem->sceneManager->GetScene("Main");
    mainScene->PushRequest(request);

    //// 로그인 안 한 상태라면 더이상 처리할 필요 없다.
    // if (clientSession->GetPlayer() == nullptr)
    //{
    //     return;
    // }

    // Packet pck((int)PacketId::Prefix::AUTH, (int)PacketId::Auth::LOGOUT_REQ);
    // pck.WriteData();
    // packetController->HandlePacket(clientSession, pck.GetByteBuffer(), pck.GetSize());
}
