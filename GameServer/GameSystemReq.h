#pragma once
#include "ClientSession.h"
#include "Player.h"

namespace GameSystemReq
{
    enum REQ_GROUP_ID : int
    {
        GLOBAL,
        POSITION
    };

    enum REQ_ID_GLOBAL : int
    {
        ENTER_SCENE = 1,
        NPC_LIST_REQ
    };

    enum REQ_ID_POSITION : int
    {
        MOVE = 1,
        NPC_MOVE
    };

    struct BaseReq
    {
    public:
        REQ_GROUP_ID commandGroupId;
        int commandId = 0;
        int playerId = 0;

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

    class NPCListReq : public BaseReq
    {
    public:
        NPCListReq() : BaseReq(REQ_GROUP_ID::GLOBAL, REQ_ID_GLOBAL::NPC_LIST_REQ){};
        sptr<Player> player;
    };

    class MoveReq : public BaseReq
    {
    public:
        MoveReq() : BaseReq(REQ_GROUP_ID::POSITION, REQ_ID_POSITION::MOVE){};
        Vector3 direction;
    };

    class NPCMoveReq : public BaseReq
    {
    public:
        NPCMoveReq() : BaseReq(REQ_GROUP_ID::POSITION, REQ_ID_POSITION::NPC_MOVE){};
        int npcId;
        Vector3 direction;
    };

} // namespace GameSystemReq
