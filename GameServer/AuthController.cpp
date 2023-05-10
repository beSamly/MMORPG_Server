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

		//[Todo] 나중에 로그인 검사 필요!!
		string email = pkt.email();
		string password = pkt.password();

		// DB 체크 이후에 Player 객체 세팅
		string sceneName = "dummy"; //[TODO] 유저가 마지막으로 로그인한 씬의 정보를 로그인 정보에서 읽어오기

		player = make_shared<Player>();
		player->playerId = request->session->clientId; // [TODO] 임시로 clientId 사용하자
		player->SetSession(request->session);
		player->currentSceneName = "Main";

		request->session->playerId = player->playerId;

		// [TODO] 일단 모두 아처 타입으로 세팅
		string characterType = "Archer";

		// 스텟 세팅
		BaseStatInfo baseStat = dataSystem->baseStatManager->GetBaseStat(1);
		player->statController->SetBaseStat(baseStat);

		// 스킬 세팅
		Skill skill = dataSystem->skillDataManager->GetSkillData(1);
		player->skillController->AddSkill(skill);

		scene = gameSystem->sceneManager->GetScene("Main");
		if (scene == nullptr)
		{
			return RES_CODE::CODE_SCENE_NOT_FOUND;
		}

		//씬에 세팅
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

	//뭘 보내야하냐...
	//기둥 충돌 테스트
	float x = 414.779f;
	float y = 113.919f;
	float z = 143.360f;

	player->SetPosition(Vector3(x, y, z));

	//씬에 접속 완료했다면 클라에게 보내준다
	Protocol::EnterSceneRes pkt;
	pkt.set_result(RES_CODE::CODE_SUCCESS);
	pkt.set_scenename("Main");
	pkt.mutable_position()->set_x(x);
	// pkt.mutable_position()->set_y(117.0f); // 공중
	pkt.mutable_position()->set_y(y);
	pkt.mutable_position()->set_z(z);

	{
		Packet packet(REQ_GROUP_ID::GAME, REQ_ID_GAME::ENTER_SCENE_RES);
		packet.WriteData<Protocol::EnterSceneRes>(pkt);
		player->Send(packet);
	}

	return result;
}
