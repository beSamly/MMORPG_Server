#include "pch.h"
#include "InputReqController.h"
#include "ResponseCode.h"
#include <Packet.h>
#include "InputMovementReq.pb.h"

using GameSystemReq::InputMovementReq;

InputReqController::InputReqController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem)
{
    mapProcessFunc.emplace(PACKET_ID_INPUT::MOVEMENT, TO_PLAYER_PACKET_PROCESS_FUNC(ProcessInputMovement));
}

int InputReqController::Process(sptr<ClientSession>& session, BYTE* buffer, int32 len)
{
    int playerId = session->playerId;

    PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

    PACKET_ID_INPUT packetId = static_cast<PACKET_ID_INPUT>(header->id);

    sptr<Player> player = gameSystem->playerManager->GetPlayer(session->playerId);
    if (player == nullptr)
    {
        LOG_ERROR("InputReqController player not found for playerId = " + session->playerId);
        return RES_CODE::CODE_PLAYER_NOT_FOUND;
    }

    PlayerPacketProcessFunc func = mapProcessFunc[packetId];
    if (func)
    {
        return func(session, player, buffer, len);
    }
    else
    {
        LOG_ERROR("InputReqController has no process function for packetId = " + packetId);
    }

    return RES_CODE::CODE_SUCCESS;
}

int InputReqController::ProcessInputMovement(sptr<ClientSession>& session, sptr<Player>& player, BYTE* buffer, int32 len)
{
    Protocol::InputMovementReq pkt;
    if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
        return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;

    sptr<InputMovementReq> command = make_shared<InputMovementReq>();
    command->playerId = session->playerId;
    command->up = pkt.up();
    command->down = pkt.down();
    command->left = pkt.left();
    command->right = pkt.right();

    sptr<Scene> scene = gameSystem->sceneManager->GetScene(player->currentSceneName);
    if (scene == nullptr)
    {
        return RES_CODE::CODE_SCENE_NOT_FOUND;
    }

    scene->PushCommand(command);
    return RES_CODE::CODE_SUCCESS;
}
