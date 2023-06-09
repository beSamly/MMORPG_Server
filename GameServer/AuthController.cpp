#include "pch.h"
#include "AuthController.h"
#include <Packet.h>
#include "RequestValidator.h"
#include <ResponseCode.h>
#include "BaseStatInfo.h"
#include <LOGIN_REQ.pb.h>
#include <LOGIN_RES.pb.h>
#include <ENTER_SCENE_RES.pb.h>

using namespace PacketDef;

#define PROCESS(FUNC) [&]() -> int { return FUNC(); }

AuthController::AuthController(sptr<GameSystem> paramGameSystem, sptr<DataSystem> paramDataSystem) : gameSystem(paramGameSystem), dataSystem(paramDataSystem)
{
    IRequestController::AddValidator([&](sptr<ClientSession>& session) -> bool { return RequestValidator::IsPlayerInScene(gameSystem, session); });

    AddProcessFunc(REQ_ID_AUTH::LOGIN_REQ, TO_REQUEST_PROCESS_FUNC(Process_LOGIN_REQ));
    AddProcessFunc(REQ_ID_AUTH::CLIENT_DISCONNECTED, TO_REQUEST_PROCESS_FUNC(Process_CLIENT_DISCONNECTED));
}

int AuthController::Process_LOGIN_REQ(sptr<Request>& request)
{
    sptr<Scene> scene = nullptr;
    sptr<Player> player = nullptr;

    int result = [&]() -> int
    {
        Protocol::LOGIN_REQ pkt;

        if (request->packet->ExtractData<Protocol::LOGIN_REQ>(pkt) == false)
        {
            return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;
        };

        //[Todo] 나중에 로그인 검사 필요!!
        string email = pkt.email();
        string password = pkt.password();

        // DB 체크 이후에 Player 객체 세팅
        string sceneName = "dummy"; //[TODO] 유저가 마지막으로 로그인한 씬의 정보를 로그인 정보에서 읽어오기

        sptr<ClientSession> session = request->session;
        player = make_shared<Player>();
        player->playerId = session->clientId; // [TODO] 임시로 clientId 사용하자
        player->SetSession(session);
        player->currentSceneName = "Main";

        session->playerId = player->playerId;

        // [TODO] 일단 모두 아처 타입으로 세팅
        string characterType = "Archer";

        // 스텟 세팅
        BaseStatInfo baseStat = dataSystem->baseStatManager->GetBaseStat(1);
        player->statController->SetBaseStat(baseStat);

        // 스킬 세팅
        //[TODO] 일단 SkillIndex = 1번인 애 세팅
        /*SkillInfo skill = dataSystem->skillDataManager->GetSkillInfo(1);
        player->skillController->AddSkill(skill);*/

        scene = gameSystem->sceneManager->GetScene("Main");
        if (scene == nullptr)
        {
            return RES_CODE::CODE_SCENE_NOT_FOUND;
        }

        gameSystem->playerManager->AddPlayer(player);

        return RES_CODE::CODE_SUCCESS;
    }();

    Protocol::LOGIN_RES res;
    res.set_result(result);

    Packet packet(REQ_GROUP_ID::AUTH, REQ_ID_AUTH::LOGIN_RES);
    packet.WriteData<Protocol::LOGIN_RES>(res);
    player->Send(packet);

    return result;
}

int AuthController::Process_CLIENT_DISCONNECTED(sptr<Request>& request)
{
    sptr<ClientSession> session = request->session;
    gameSystem->clientManager->RemoveClient(session->clientId);

    sptr<Player> player = gameSystem->playerManager->GetPlayer(session->playerId);
    if (player)
    {
        LOG_DEBUG("Client Disconnected - removing player from playerManager playerId = " + session->playerId);
        gameSystem->playerManager->RemovePlayer(session->playerId);

        sptr<Scene> scene = gameSystem->sceneManager->GetScene(player->currentSceneName);
        if (scene)
        {
            LOG_DEBUG("Client Disconnected - removing player from scene = " + player->currentSceneName);
            scene->RemovePlayer(session->playerId);
        }
    }

    return RES_CODE::CODE_SUCCESS;
}
