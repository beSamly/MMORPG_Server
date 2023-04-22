#include "pch.h"
#include "AuthController.h"
#include <Packet.h>
#include "LoginReq.pb.h"
#include "RequestValidator.h"
#include <LoginRes.pb.h>
#include <ResponseCode.h>
#include "BaseStatInfo.h"

using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_AUTH;

using GameSystemReq::EnterSceneReq;

#define PROCESS(FUNC) [&]() -> int { return FUNC(); }

AuthController::AuthController(sptr<GameSystem> paramGameSystem, sptr<DataSystem> paramDataSystem, sptr<Logger> paramLogger)
    : gameSystem(paramGameSystem), dataSystem(paramDataSystem), logger(paramLogger)
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
        logger->Error("AuthController has no process function for packetId = " + packetId);
    }
}

int AuthController::ProcessLoginReq(sptr<ClientSession>& session, BYTE* buffer, int32 len)
{
    sptr<Scene> scene = nullptr;
    sptr<Player> player = nullptr;

    int result = [&]() -> int
    {
        Protocol::LoginReq pkt;
        if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
            return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;

        //[Todo] 나중에 로그인 검사 필요!!
        string email = pkt.email();
        string password = pkt.password();

        // DB 체크 이후에 Player 객체 세팅
        int playerId = 1;
        string sceneName = "dummy"; //[TODO] 유저가 마지막으로 로그인한 씬의 정보를 로그인 정보에서 읽어오기

        player = make_shared<Player>();
        player->playerId = playerId;
        player->SetSession(session);

        // [TODO] 일단 모두 아처 타입으로 세팅
        string characterType = "Archer";

        // 스텟 세팅
        BaseStatInfo baseStat = dataSystem->baseStatManager->GetBaseStat(1);
        player->statController->SetBaseStat(baseStat);

        scene = gameSystem->sceneManager->GetScene("Main");

        if (scene == nullptr)
        {
            return RES_CODE::CODE_SCENE_NOT_FOUND;
        }

        return RES_CODE::CODE_SUCCESS;
    }();

    Protocol::LoginRes res;
    res.set_result(result);

    Packet packet(PACKET_GROUP_ID::AUTH, PACKET_ID_AUTH::LOGIN_RES);
    packet.WriteData<Protocol::LoginRes>(res);
    session->Send(packet.GetSendBuffer());

    sptr<EnterSceneReq> command = make_shared<EnterSceneReq>();
    command->player = player;
    scene->PushCommand(command);
    return result;
}
