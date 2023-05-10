#pragma once
#include "ClientSession.h"
#include "Player.h"

namespace GameSystemReq
{
	enum GAME_REQ_GROUP_ID : int
	{
		GLOBAL,
		POSITION,
		GAME
	};

	enum GAME_REQ_ID_GLOBAL : int
	{
		ENTER_SCENE = 1,
		NPC_LIST_REQ
	};

	enum GAME_REQ_ID_GAME : int
	{
		MOVE = 1,
		NPC_MOVE
	};

	struct BaseReq
	{
	public:
		GAME_REQ_GROUP_ID commandGroupId;
		int commandId = 0;
		int playerId = 0;

	public:
		BaseReq(GAME_REQ_GROUP_ID paramCommandGroupId, int paramCommandId) : commandGroupId(paramCommandGroupId), commandId(paramCommandId) {};
		// BaseReq(int paramPlayerId, COMMAND_ID paramCommandId) : playerId(paramPlayerId),
		// commandId(paramCommandId){};
		virtual int GetCommandId() { return commandId; };
	};

	class EnterSceneReq : public BaseReq
	{
	public:
		EnterSceneReq() : BaseReq(GAME_REQ_GROUP_ID::GLOBAL, GAME_REQ_ID_GLOBAL::ENTER_SCENE) {};

		string sceneName;
		sptr<Player> player;
	};

	class NPCListReq : public BaseReq
	{
	public:
		NPCListReq() : BaseReq(GAME_REQ_GROUP_ID::GLOBAL, GAME_REQ_ID_GLOBAL::NPC_LIST_REQ) {};
		sptr<Player> player;
	};

	class MoveReq : public BaseReq
	{
	public:
		MoveReq() : BaseReq(GAME_REQ_GROUP_ID::GAME, GAME_REQ_ID_GAME::MOVE) {};
		Vector3 direction;
	};

	class NPCMoveReq : public BaseReq
	{
	public:
		NPCMoveReq() : BaseReq(GAME_REQ_GROUP_ID::GAME, GAME_REQ_ID_GAME::NPC_MOVE) {};
		int npcId;
		Vector3 direction;
	};

} // namespace GameSystemReq
