#pragma once
#include "pch.h"
#include "Scene.h"
#include "GameSystem.h"
#include "Player.h"

using GameSystemReq::BaseReq;

namespace GameSystemReqProcessCommon
{
    typedef function<int(sptr<Scene>& scene, sptr<BaseReq>& command)> BaseCommandProcessFunc;
    typedef function<int(sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command)> PlayerCommandProcessFunc;

#define TO_BASE_COMMAND_PROCESS_FUNC(FUNC) [&](sptr<Scene>& scene, sptr<BaseReq>& command) { return FUNC(scene, command); }
#define TO_PLAYER_COMMAND_PROCESS_FUNC(FUNC) [&](sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command) { return FUNC(scene, player, command); }

} // namespace GameSystemReqProcessCommon

