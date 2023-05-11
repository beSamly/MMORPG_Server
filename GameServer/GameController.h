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
    int Process_MOVE_REQ(sptr<Request>& request);
    int Process_NPC_LIST_REQ(sptr<Request>& request);
    int Process_ENTER_SCENE_REQ(sptr<Request>& request);
    int Process_USE_SKILL_REQ(sptr<Request>& request);
};
