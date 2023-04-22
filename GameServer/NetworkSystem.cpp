#include "pch.h"
#include "NetworkSystem.h"
#include "spdlog/spdlog.h"
#include "Packet.h"
#include "Logger.h"
#include "NetworkControllerContainer.h"

namespace
{
	int32 PORT = 5000;
	int32 MAX_SESSION_COUNT = 100;
} // namespace

NetworkSystem::NetworkSystem(sptr<DataSystem> paramDataSystem, sptr<GameSystem> paramGameSystem)
	: dataSystem(paramDataSystem), gameSystem(paramGameSystem)
{
	context = make_shared<asio::io_context>();
	socketServer = make_shared<SocketServer>(context, PORT);
	clientManager = make_unique<ClientManager>();
	logger = make_shared<Logger>("Dummy file path");

	networkControllerContainer = make_shared<NetworkControllerContainer>(gameSystem, dataSystem, logger);
}

void NetworkSystem::StartSocketServer()
{
	// 소켓 서버 실행
	socketServer->SetOnAcceptCallback([&](sptr<AsioSession> client) { OnClientAccept(client); });
	socketServer->SetOnClientRecv([&](sptr<AsioSession> client, BYTE* buffer, int len)
		{ OnClientRecv(client, buffer, len); });
	socketServer->SetOnClientDisconnect([&](sptr<AsioSession> client) { OnClientDisconnect(client); });
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
		return;
	}

	clientManager->AddClient(clientSession);
	return;
}

void NetworkSystem::OnClientRecv(sptr<AsioSession> client, BYTE* buffer, int len)
{
	sptr<ClientSession> clientSession = dynamic_pointer_cast<ClientSession>(client);

	if (!clientSession)
	{
		return;
	}

	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	sptr<INetworkController> controller = networkControllerContainer->GetController(header->groupId);
	if (controller)
	{
		controller->Process(clientSession, buffer, len);
	}
	else
	{
		logger->Error("NetworkControllerContainer has no controller for groupId = " + header->groupId);
	}

	// if (clientSession->isAuthenticated)
	//{
	//     playerPacketController->HandleClientPacket(clientSession, buffer, len);
	// }
	// else
	//{
	//     clientPacketController->HandleClientPacket(clientSession, buffer, len);
	// }
}

void NetworkSystem::OnClientDisconnect(sptr<AsioSession> client)
{
	spdlog::debug("[NetworkSystem] Client disconnected");

	// sptr<ClientSession> clientSession = dynamic_pointer_cast<ClientSession>(client);

	// if (!clientSession)
	//{
	//     return;
	// }

	//// 로그인 안 한 상태라면 더이상 처리할 필요 없다.
	// if (clientSession->GetPlayer() == nullptr)
	//{
	//     return;
	// }

	// Packet pck((int)PacketId::Prefix::AUTH, (int)PacketId::Auth::LOGOUT_REQ);
	// pck.WriteData();
	// packetController->HandlePacket(clientSession, pck.GetByteBuffer(), pck.GetSize());
}
