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

        //[Todo] ���߿� �α��� �˻� �ʿ�!!
        string email = pkt.email();
        string password = pkt.password();

        // DB üũ ���Ŀ� Player ��ü ����
        string sceneName = "dummy"; //[TODO] ������ ���������� �α����� ���� ������ �α��� �������� �о����

        sptr<ClientSession> session = request->session;
        player = make_shared<Player>();
        player->playerId = session->clientId; // [TODO] �ӽ÷� clientId �������
        player->SetSession(session);
        player->currentSceneName = "Main";

        session->playerId = player->playerId;

        // [TODO] �ϴ� ��� ��ó Ÿ������ ����
        string characterType = "Archer";

        // ���� ����
        BaseStatInfo baseStat = dataSystem->baseStatManager->GetBaseStat(1);
        player->statController->SetBaseStat(baseStat);

        // ��ų ����
        //[TODO] �ϴ� SkillIndex = 1���� �� ����
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
