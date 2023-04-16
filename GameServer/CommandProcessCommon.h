#pragma once
#include "pch.h"
#include "Scene.h"
#include "GameSystem.h"
#include "Player.h"

using Command::CommandBase;

namespace SceneCommandProcessCommon
{
    typedef function<int(GameSystem& gameSystem, sptr<Scene>& scene, sptr<CommandBase>& command)> BaseCommandProcessFunc;
    typedef function<int(GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<CommandBase>& command)> PlayerCommandProcessFunc;

#define TO_BASE_COMMAND_PROCESS_FUNC(FUNC) [&](GameSystem& gameSystem, sptr<Scene>& scene, sptr<CommandBase>& command) { return FUNC(gameSystem, scene, command); }
#define TO_PLAYER_COMMAND_PROCESS_FUNC(FUNC) [&](GameSystem& gameSystem, sptr<Scene>& scene, sptr<Player>& player, sptr<CommandBase>& command) { return FUNC(gameSystem, scene, player, command); }

} // namespace SceneCommandProcessCommon

namespace GameSystemCommandProcessCommon
{
    typedef function<int(GameSystem& gameSystem, sptr<CommandBase>& command)> BaseCommandProcessFun;

#define TO_BASE_PROCESS_FUNC(FUNC) [&](GameSystem& gameSystem, sptr<CommandBase>& command) { return FUNC(gameSystem, command); }

} // namespace GameSystemCommandProcessCommon