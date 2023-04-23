#include "pch.h"
#include "GameGlobalController.h"
#include "Logger.h"
#include "GameSystem.h"
#include "PacketDef.h"
#include <Packet.h>
#include "EnterSceneRes.pb.h"
#include "Vector3.pb.h"
#include <ResponseCode.h>

using GameSystemReq::EnterSceneReq;
using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_GLOBAL;

GameGlobalController::GameGlobalController(sptr<GameSystem> paramGameSystem, sptr<Logger> paramLogger) : gameSystem(paramGameSystem), logger(paramLogger)
{
    mapProcessFunc.emplace(REQ_ID_GLOBAL::ENTER_SCENE, TO_BASE_COMMAND_PROCESS_FUNC(ProcessEnterScene));

    // mapProcessFunc[COMMAND_ID_GAME_SYSTEM_GLOBAL::PLAYER_LOG_IN] = TO_BASE_COMMAND_PROCESS_FUNC(ProcessEnterScene);
}

int GameGlobalController::Process(sptr<Scene>& scene, sptr<BaseReq>& command)
{
    REQ_ID_GLOBAL commandId = static_cast<REQ_ID_GLOBAL>(command->commandId);
    BaseCommandProcessFunc func = mapProcessFunc[commandId];
    if (func)
    {
        return func(scene, command);
    }
    else
    {
        // logger->Error("GameGlobalController has no process function for commandId = {}", command->commandId);
        return RES_CODE::CODE_PROCESS_FUNC_NOT_FOUND;
    }
}

int GameGlobalController::ProcessEnterScene(sptr<Scene>& scene, sptr<BaseReq>& command)
{
    sptr<EnterSceneReq> enterSceneReq = dynamic_pointer_cast<EnterSceneReq>(command);
    if (enterSceneReq == nullptr)
    {
        return RES_CODE::CODE_STRUCT_TYPE_MISMATCH;
    }

    sptr<Player> player = enterSceneReq->player;

    gameSystem->playerManager->AddPlayer(player);
    scene->AddPlayerId(player->playerId);

    float x = 420.0f;
    float y = 117.0f;
    float z = 143.0f;

    //씬에 접속 완료했다면 클라에게 보내준다
    Protocol::EnterSceneRes pkt;
    pkt.set_result(RES_CODE::CODE_SUCCESS);
    pkt.set_scenename("Main");
    pkt.mutable_position()->set_x(420.0f);
    pkt.mutable_position()->set_y(117.0f);
    pkt.mutable_position()->set_z(143.0f);

    Packet packet(PACKET_GROUP_ID::GLOBAL, PACKET_ID_GLOBAL::ENTER_SCENE_RES);
    packet.WriteData<Protocol::EnterSceneRes>(pkt);
    player->Send(packet.GetSendBuffer());

    player->transformController->SetPosition(Vector3(x, y, z));
    return RES_CODE::CODE_SUCCESS;
}
