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

    //[Todo] 나중에 로그인 검사 필요!!
    string email = pkt.email();
    string password = pkt.password();

    // DB 체크 이후에 Player 객체 세팅

    int playerId = 1;
    string sceneName = "dummy"; //[TODO] 유저가 마지막으로 로그인한 씬의 정보를 로그인 정보에서 읽어오기

    sptr<Player> player = make_shared<Player>();
    player->SetPlayerId(playerId);
    session->isAuthenticated = true;

    // Scene에 넣어준다.
    sptr<CommandPlayerLogIn> command = make_shared<CommandPlayerLogIn>();
    command->sceneName = sceneName;
    command->player = player;

    gameSystem->PushCommand(command);

    using NetworkResponseCode::CODE_SUCCESS;
}
