#pragma once

namespace PacketDef {

enum PACKET_GROUP_ID : int {
  AUTH = 1,
  INPUT,
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

enum PACKET_ID_INPUT : int {
  MOVEMENT = 1,
};

}  // namespace PacketDef