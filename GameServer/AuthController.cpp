#include "pch.h"
#include "AuthController.h"
#include <Packet.h>
#include "LoginReq.pb.h"
#include "RequestValidator.h"
#include <LoginRes.pb.h>
#include <ResponseCode.h>
#include "BaseStatInfo.h"
#include "EnterSceneRes.pb.h"

using namespace PacketDef;

#define PROCESS(FUNC) [&]() -> int { return FUNC(); }

AuthController::AuthController(sptr<GameSystem> paramGameSystem, sptr<DataSystem> paramDataSystem)
	: gameSystem(paramGameSystem), dataSystem(paramDataSystem)
{
	IRequestController::AddValidator([&](sptr<ClientSession>& session) -> bool { return RequestValidator::IsPlayerInScene(gameSystem, session); });

	AddProcessFunc(REQ_ID_AUTH::LOGIN_REQ, TO_REQUEST_PROCESS_FUNC(ProcessLoginReq));
}

int AuthController::ProcessLoginReq(sptr<Request>& request)
{
	sptr<Scene> scene = nullptr;
	sptr<Player> player = nullptr;

	int result = [&]() -> int
	{
		Protocol::LoginReq pkt;
		if (request->packet->ExtractData<Protocol::LoginReq>(pkt) == false) {
			return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;
		};

		//[Todo] ���߿� �α��� �˻� �ʿ�!!
		string email = pkt.email();
		string password = pkt.password();

		// DB üũ ���Ŀ� Player ��ü ����
		string sceneName = "dummy"; //[TODO] ������ ���������� �α����� ���� ������ �α��� �������� �о����

		player = make_shared<Player>();
		player->playerId = request->session->clientId; // [TODO] �ӽ÷� clientId �������
		player->SetSession(request->session);
		player->currentSceneName = "Main";

		request->session->playerId = player->playerId;

		// [TODO] �ϴ� ��� ��ó Ÿ������ ����
		string characterType = "Archer";

		// ���� ����
		BaseStatInfo baseStat = dataSystem->baseStatManager->GetBaseStat(1);
		player->statController->SetBaseStat(baseStat);

		// ��ų ����
		Skill skill = dataSystem->skillDataManager->GetSkillData(1);
		player->skillController->AddSkill(skill);

		scene = gameSystem->sceneManager->GetScene("Main");
		if (scene == nullptr)
		{
			return RES_CODE::CODE_SCENE_NOT_FOUND;
		}

		//���� ����
		sptr<Player> player = request->from;

		gameSystem->playerManager->AddPlayer(player);
		scene->AddPlayerId(player->playerId);



		return RES_CODE::CODE_SUCCESS;
	}();

	Protocol::LoginRes res;
	res.set_result(result);

	{
		Packet packet(REQ_GROUP_ID::AUTH, REQ_ID_AUTH::LOGIN_RES);
		packet.WriteData<Protocol::LoginRes>(res);
		player->Send(packet);
	}

	//�� �������ϳ�...
	//��� �浹 �׽�Ʈ
	float x = 414.779f;
	float y = 113.919f;
	float z = 143.360f;

	player->SetPosition(Vector3(x, y, z));

	//���� ���� �Ϸ��ߴٸ� Ŭ�󿡰� �����ش�
	Protocol::EnterSceneRes pkt;
	pkt.set_result(RES_CODE::CODE_SUCCESS);
	pkt.set_scenename("Main");
	pkt.mutable_position()->set_x(x);
	// pkt.mutable_position()->set_y(117.0f); // ����
	pkt.mutable_position()->set_y(y);
	pkt.mutable_position()->set_z(z);

	{
		Packet packet(REQ_GROUP_ID::GAME, REQ_ID_GAME::ENTER_SCENE_RES);
		packet.WriteData<Protocol::EnterSceneRes>(pkt);
		player->Send(packet);
	}

	return result;
}
