#pragma once
#include "pch.h"
#include "Scene.h"
#include "GameSystem.h"
#include "Player.h"

using GameSystemReq::BaseReq;

namespace SceneCommandProcessCommon
{
    typedef function<int(GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command)> BaseCommandProcessFunc;
    typedef function<int(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command)> PlayerCommandProcessFunc;

#define TO_BASE_COMMAND_PROCESS_FUNC(FUNC) [&](GameSystem& gameSystem, sptr<Scene>& scene, sptr<BaseReq>& command) { return FUNC(gameSystem, scene, command); }
#define TO_PLAYER_COMMAND_PROCESS_FUNC(FUNC) [&](GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<BaseReq>& command) { return FUNC(gameSystem, scene, player, command); }

} // namespace SceneCommandProcessCommon

namespace GameSystemCommandProcessCommon
{
    typedef function<int(GameSystem& gameSystem, sptr<BaseReq>& command)> BaseCommandProcessFun;

#define TO_BASE_PROCESS_FUNC(FUNC) [&](GameSystem& gameSystem, sptr<BaseReq>& command) { return FUNC(gameSystem, command); }

} // namespace GameSystemCommandProcessCommon