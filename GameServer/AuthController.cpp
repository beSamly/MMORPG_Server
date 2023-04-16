#include "pch.h"
#include "AuthController.h"
#include <Packet.h>
#include "LoginReq.pb.h"
#include <NetworkResponseCode.h>
#include "RequestValidator.h"

using Command::CommandPlayerLogIn;
using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_AUTH;

AuthController::AuthController(sptr<GameSystem> paramGameSystem, sptr<Logger> paramLogger) : gameSystem(paramGameSystem), logger(paramLogger)
{
    INetworkController::AddValidator([&](sptr<ClientSession>& session) -> bool { return RequestValidator::IsPlayerInScene(gameSystem, session); });

    mapProcessFunc.emplace(PACKET_ID_AUTH::LOGIN_REQ, TO_BASE_PACKET_PROCESS_FUNC(ProcessLoginReq));
    // mapProcessFunc[PACKET_ID_AUTH::LOGIN_REQ] = TO_BASE_PACKET_PROCESS_FUNC(ProcessLoginReq);
}

int AuthController::Process(sptr<ClientSession>& session, BYTE* buffer, int32 len)
{
    PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

    PACKET_ID_AUTH packetId = static_cast<PACKET_ID_AUTH>(header->id);

    BasePacketProcessFunc func = mapProcessFunc[packetId];

    if (func)
    {
        return func(session, buffer, len);
    }
    else
    {
        logger->Error("AuthController has no process function for packetId = {}", packetId);
    }
}

int AuthController::ProcessLoginReq(sptr<ClientSession>& session, BYTE* buffer, int32 len)
{
    Protocol::LoginReq pkt;
    if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
        return NetworkResponseCode::CODE_PROTOBUF_PARSE_FAIL;

    //[Todo] ���߿� �α��� �˻� �ʿ�!!
    string email = pkt.email();
    string password = pkt.password();

    // DB üũ ���Ŀ� Player ��ü ����

    int playerId = 1;
    string sceneName = "dummy"; //[TODO] ������ ���������� �α����� ���� ������ �α��� �������� �о����

    sptr<Player> player = make_shared<Player>();
    player->SetPlayerId(playerId);
    session->isAuthenticated = true;

    // Scene�� �־��ش�.
    sptr<CommandPlayerLogIn> command = make_shared<CommandPlayerLogIn>();
    command->sceneName = sceneName;
    command->player = player;

    gameSystem->PushCommand(command);

    using NetworkResponseCode::CODE_SUCCESS;
}
