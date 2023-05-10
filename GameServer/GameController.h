#pragma once
#include "IRequestController.h"
#include "Logger.h"
#include <PacketDef.h>
#include "GameSystem.h"

using namespace PacketDef;

class GameController : public IRequestController
{
private:
	sptr<GameSystem> gameSystem;

public:
	GameController(sptr<GameSystem> gameSystem);
	int ProcessMoveReq(sptr<Request>& request);
	int ProcessNPCListReq(sptr<Request>& request);
};
