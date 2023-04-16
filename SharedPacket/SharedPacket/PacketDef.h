#pragma once

namespace PacketDef {

enum PACKET_GROUP_ID : int {
  AUTH = 0,
  INPUT,
  SCENE
};

enum PACKET_ID_AUTH : int {
  LOGIN_REQ = 0,
  LOGIN_RES,
};

enum PACKET_ID_SCENE : int {
  ENTER_SCENE_REQ = 0,
  ENTER_SCENE_RES,
};

enum PACKET_ID_INPUT : int {
  MOVEMENT = 0,
};

}  // namespace PacketDef