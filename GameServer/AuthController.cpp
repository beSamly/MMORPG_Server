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

	//	//[Todo] 나중에 로그인 검사 필요!!
	//	string email = pkt.email();
	//	string password = pkt.password();

	//	// DB 체크 이후에 Player 객체 세팅
	//	string sceneName = "dummy"; //[TODO] 유저가 마지막으로 로그인한 씬의 정보를 로그인 정보에서 읽어오기

	//	player = make_shared<Player>();
	//	player->playerId = session->clientId; // [TODO] 임시로 clientId 사용하자
	//	player->SetSession(session);
	//	player->currentSceneName = "Main";
	//	session->playerId = player->playerId;

	//	// [TODO] 일단 모두 아처 타입으로 세팅
	//	string characterType = "Archer";

	//	// 스텟 세팅
	//	BaseStatInfo baseStat = dataSystem->baseStatManager->GetBaseStat(1);
	//	player->statController->SetBaseStat(baseStat);

	//	// 스킬 세팅
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
