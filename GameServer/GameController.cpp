#include "pch.h"
#include "GameController.h"
#include "ResponseCode.h"
#include <Packet.h>
#include "InputMovementReq.pb.h"
#include "MoveReq.pb.h"

GameController::GameController(sptr<GameSystem> paramGameSystem) : gameSystem(paramGameSystem) {
	AddProcessFunc(REQ_ID_GAME::MOVE_REQ, TO_REQUEST_PROCESS_FUNC(ProcessMoveReq));
}


int GameController::ProcessMoveReq(sptr<Request>& request)
{
	/*Protocol::MoveReq pkt;
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

	scene->PushRequest(command);
	return RES_CODE::CODE_SUCCESS;*/

	return 0;
}


int GameController::ProcessNPCListReq(sptr<Request>& request)
{
	/*sptr<GameSystemReq::NPCListReq> command = make_shared<GameSystemReq::NPCListReq>();
	command->player = player;

	sptr<Scene> scene = gameSystem->sceneManager->GetScene("Main");
	if (scene == nullptr)
	{
		return RES_CODE::CODE_SCENE_NOT_FOUND;
	}
	else
	{
		scene->PushRequest(command);
		return RES_CODE::CODE_SUCCESS;
	}*/

	return 0;
}

