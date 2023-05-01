#include "pch.h"
#include "GlobalController.h"
#include "ResponseCode.h"
#include <Packet.h>
#include "INetworkController.h"

using GameSystemReq::MoveReq;
using PacketDef::PACKET_ID_GLOBAL;

GlobalController::GlobalController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem) { mapProcessFunc.emplace(PACKET_ID_GLOBAL::NPC_LIST_REQ, TO_PLAYER_PACKET_PROCESS_FUNC(ProcessNPCListReq)); }

int GlobalController::Process(sptr<ClientSession>& session, BYTE* buffer, int32 len)
{
    int playerId = session->playerId;

    PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

    PACKET_ID_GLOBAL packetId = static_cast<PACKET_ID_GLOBAL>(header->id);

    sptr<Player> player = gameSystem->playerManager->GetPlayer(session->playerId);
    if (player == nullptr)
    {
        LOG_ERROR("GlobalController player not found for playerId = " + std::to_string(session->playerId));
        return RES_CODE::CODE_PLAYER_NOT_FOUND;
    }

    PlayerPacketProcessFunc func = mapProcessFunc[packetId];
    if (func)
    {
        return func(session, player, buffer, len);
    }
    else
    {
        LOG_ERROR("GlobalController has no process function for packetId = " + std::to_string(packetId));
    }

    return RES_CODE::CODE_SUCCESS;
}

int GlobalController::ProcessNPCListReq(sptr<ClientSession>& session, sptr<Player>& player, BYTE* buffer, int32 len)
{
    sptr<GameSystemReq::NPCListReq> command = make_shared<GameSystemReq::NPCListReq>();
    command->player = player;

    sptr<Scene> scene = gameSystem->sceneManager->GetScene("Main");
    if (scene == nullptr)
    {
        return RES_CODE::CODE_SCENE_NOT_FOUND;
    }
    else
    {
        scene->PushCommand(command);
        return RES_CODE::CODE_SUCCESS;
    }
}
