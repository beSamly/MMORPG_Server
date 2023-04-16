#pragma once
#include "ClientSession.h"
#include "ProxyManager.h"
#include "Player.h"

namespace CommandResult
{
    const int COMMAND_RESULT_SUCCESS = 0;
    const int SCENE_NOT_FOUND = -1;
    const int PLAYER_NOT_FOUND = -2;
    const int PROCESS_FUNC_NOT_FOUND = -3;
    const int COMMAND_TYPE_MISMATCH = -4;
} // namespace CommandResult

namespace Command
{
    enum COMMAND_GROUP_ID : int
    {
        GAME_SYSTEM_GLOBAL = 1,
        SCENE_GLOBAL,
        INPUT
    };

    enum COMMAND_ID_GAME_SYSTEM_GLOBAL : int
    {
        PLAYER_LOG_IN = 1
    };

    enum COMMAND_ID_SCENE_GLOBAL : int
    {
        ENTER_SCENE = 1
    };

    enum COMMAND_ID_INPUT : int
    {
        MOVEMENT = 1
    };

    struct CommandBase
    {
    public:
        int playerId = 0;
        COMMAND_GROUP_ID commandGroupId;
        int commandId = 0;

    public:
        CommandBase(COMMAND_GROUP_ID paramCommandGroupId, int paramCommandId) : commandGroupId(paramCommandGroupId), commandId(paramCommandId){};
        // CommandBase(int paramPlayerId, COMMAND_ID paramCommandId) : playerId(paramPlayerId),
        // commandId(paramCommandId){};
        virtual int GetCommandId() { return commandId; };
    };

    class CommandPlayerLogIn : public CommandBase
    {
    public:
        CommandPlayerLogIn() : CommandBase(COMMAND_GROUP_ID::GAME_SYSTEM_GLOBAL, COMMAND_ID_GAME_SYSTEM_GLOBAL::PLAYER_LOG_IN){};

        string sceneName;
        sptr<Player> player;
    };

    class CommandEnterScene : public CommandBase
    {
    public:
        CommandEnterScene() : CommandBase(COMMAND_GROUP_ID::SCENE_GLOBAL, COMMAND_ID_SCENE_GLOBAL::ENTER_SCENE){};

        string sceneName;
        sptr<Player> player;
    };

    class CommandInputMovement : public CommandBase
    {
    public:
        CommandInputMovement() : CommandBase(COMMAND_GROUP_ID::INPUT, COMMAND_ID_INPUT::MOVEMENT){};

        bool up;
        bool down;
        bool left;
        bool right;
    };

} // namespace Command
