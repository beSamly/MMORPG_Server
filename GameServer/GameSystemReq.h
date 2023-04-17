#pragma once
#include "ClientSession.h"
#include "Player.h"

namespace GameSystemReq
{
    enum RESULT_TYPE : int
    {
        SUCCESS = 0,
        SCENE_NOT_FOUND,
        PLAYER_NOT_FOUND,
        PROCESS_FUNC_NOT_FOUND,
        STRUCT_TYPE_MISMATCH
    };

    enum REQ_GROUP_ID : int
    {
        GLOBAL,
        INPUT
    };

    enum REQ_ID_GLOBAL : int
    {
        ENTER_SCENE = 1
    };

    enum REQ_ID_INPUT : int
    {
        MOVEMENT = 1
    };

    struct BaseReq
    {
    public:
        REQ_GROUP_ID    commandGroupId;
        int             commandId = 0;
        int             playerId = 0;


    public:
        BaseReq(REQ_GROUP_ID paramCommandGroupId, int paramCommandId) : commandGroupId(paramCommandGroupId), commandId(paramCommandId){};
        // BaseReq(int paramPlayerId, COMMAND_ID paramCommandId) : playerId(paramPlayerId),
        // commandId(paramCommandId){};
        virtual int GetCommandId() { return commandId; };
    };

    class EnterSceneReq : public BaseReq
    {
    public:
        EnterSceneReq() : BaseReq(REQ_GROUP_ID::GLOBAL, REQ_ID_GLOBAL::ENTER_SCENE){};

        string sceneName;
        sptr<Player> player;
    };

    class InputMovementReq : public BaseReq
    {
    public:
        InputMovementReq() : BaseReq(REQ_GROUP_ID::INPUT, REQ_ID_INPUT::MOVEMENT){};

        bool up;
        bool down;
        bool left;
        bool right;
    };

} // namespace GameSystemReq
