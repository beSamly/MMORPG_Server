#include "pch.h"
#include "PositionController.h"
#include "ResponseCode.h"
#include <Packet.h>
#include "InputMovementReq.pb.h"
#include "MoveReq.pb.h"

using GameSystemReq::MoveReq;

PositionController::PositionController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem) { mapProcessFunc.emplace(PACKET_ID_POSITION::MOVE_REQ, TO_PLAYER_PACKET_PROCESS_FUNC(ProcessMoveReq)); }

int PositionController::Process(sptr<ClientSession>& session, BYTE* buffer, int32 len)
{
    int playerId = session->playerId;

    PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

    PACKET_ID_POSITION packetId = static_cast<PACKET_ID_POSITION>(header->id);

    sptr<Player> player = gameSystem->playerManager->GetPlayer(session->playerId);
    if (player == nullptr)
    {
        LOG_ERROR("PositionController player not found for playerId = " + std::to_string(session->playerId));
        return RES_CODE::CODE_PLAYER_NOT_FOUND;
    }

    PlayerPacketProcessFunc func = mapProcessFunc[packetId];
    if (func)
    {
        return func(session, player, buffer, len);
    }
    else
    {
        LOG_ERROR("PositionController has no process function for packetId = " + std::to_string(packetId));
    }

    return RES_CODE::CODE_SUCCESS;
}

int PositionController::ProcessMoveReq(sptr<ClientSession>& session, sptr<Player>& player, BYTE* buffer, int32 len)
{
    Protocol::MoveReq pkt;
    if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
        return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;

    sptr<MoveReq> command = make_shared<MoveReq>();
    command->playerId = session->playerId;
    command->direction.x = pkt.direction().x();
    command->direction.y = pkt.direction().y();
    command->direction.z = pkt.direction().z();

    sptr<Scene> scene = gameSystem->sceneManager->GetScene(player->currentSceneName);
    if (scene == nullptr)
    {
        return RES_CODE::CODE_SCENE_NOT_FOUND;
    }

    scene->PushCommand(command);
    return RES_CODE::CODE_SUCCESS;
}
