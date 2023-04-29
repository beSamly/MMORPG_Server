#pragma once

namespace PacketDef {

enum PACKET_GROUP_ID : int {
  AUTH = 1,
  POSITION,
  GLOBAL,
};

enum PACKET_ID_AUTH : int {
  LOGIN_REQ = 1,
  LOGIN_RES,
};

enum PACKET_ID_GLOBAL : int {
  ENTER_SCENE_REQ = 1,
  ENTER_SCENE_RES,
  
};

enum PACKET_ID_POSITION : int {
  POSITION_UPDATE = 1,
  MOVE_REQ,
  MOVE_RES,
};

}  // namespace PacketDef