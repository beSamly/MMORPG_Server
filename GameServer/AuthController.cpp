#include "pch.h"
#include "AuthController.h"
#include <Packet.h>
#include "LoginReq.pb.h"
#include "RequestValidator.h"
#include <LoginRes.pb.h>
#include <ResponseCode.h>
#include "BaseStatInfo.h"

using PacketDef::REQ_GROUP_ID;
using PacketDef::REQ_ID_AUTH;

using GameSystemReq::EnterSceneReq;

#define PROCESS(FUNC) [&]() -> int { return FUNC(); }

AuthController::AuthController(sptr<GameSystem> paramGameSystem, sptr<DataSystem> paramDataSystem)
	: gameSystem(paramGameSystem), dataSystem(paramDataSystem)
{
	IRequestController::AddValidator([&](sptr<ClientSession>& session) -> bool { return RequestValidator::IsPlayerInScene(gameSystem, session); });

	AddProcessFunc(REQ_ID_AUTH::LOGIN_REQ, TO_REQUEST_PROCESS_FUNC(ProcessLoginReq));
}


int AuthController::ProcessLoginReq(sptr<Request>& request)
{
	//sptr<Scene> scene = nullptr;
	//sptr<Player> player = nullptr;

	//int result = [&]() -> int
	//{
	//	Protocol::LoginReq pkt;
	//	if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
	//		return RES_CODE::CODE_PROTOBUF_PARSE_FAIL;

	//	//[Todo] ���߿� �α��� �˻� �ʿ�!!
	//	string email = pkt.email();
	//	string password = pkt.password();

	//	// DB üũ ���Ŀ� Player ��ü ����
	//	string sceneName = "dummy"; //[TODO] ������ ���������� �α����� ���� ������ �α��� �������� �о����

	//	player = make_shared<Player>();
	//	player->playerId = session->clientId; // [TODO] �ӽ÷� clientId �������
	//	player->SetSession(session);
	//	player->currentSceneName = "Main";
	//	session->playerId = player->playerId;

	//	// [TODO] �ϴ� ��� ��ó Ÿ������ ����
	//	string characterType = "Archer";

	//	// ���� ����
	//	BaseStatInfo baseStat = dataSystem->baseStatManager->GetBaseStat(1);
	//	player->statController->SetBaseStat(baseStat);

	//	// ��ų ����
	//	Skill skill = dataSystem->skillDataManager->GetSkillData(1);
	//	player->skillController->AddSkill(skill);

	//	scene = gameSystem->sceneManager->GetScene("Main");
	//	if (scene == nullptr)
	//	{
	//		return RES_CODE::CODE_SCENE_NOT_FOUND;
	//	}

	//	return RES_CODE::CODE_SUCCESS;
	//}();

	//Protocol::LoginRes res;
	//res.set_result(result);

	//Packet packet(REQ_GROUP_ID::AUTH, REQ_ID_AUTH::LOGIN_RES);
	//packet.WriteData<Protocol::LoginRes>(res);
	//session->Send(packet);

	//if (result == RES_CODE::CODE_SUCCESS)
	//{
	//	LOG_INFO("login success for playerId = " + std::to_string(player->playerId));

	//	sptr<EnterSceneReq> command = make_shared<EnterSceneReq>();
	//	command->player = player;
	//	scene->PushRequest(command);
	//}

	//return result;

	return 0;
}
