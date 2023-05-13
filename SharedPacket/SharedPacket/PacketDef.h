#pragma once

namespace PacketDef {

enum REQ_GROUP_ID : int { AUTH = 1, GAME };

enum REQ_ID_AUTH : int { LOGIN_REQ = 1, LOGIN_RES, CLIENT_DISCONNECTED };

enum REQ_ID_GAME : int {
  ENTER_SCENE_REQ = 1,
  ENTER_SCENE_RES,
  NPC_LIST_REQ,
  NPC_LIST_RES,
  POSITION_UPDATE,
  MOVE_REQ,
  MOVE_RES,
  NPC_SPAWNED_LIST,
  USE_SKILL_REQ,
  USE_SKILL_RES
};

}  // namespace PacketDef