#pragma once
struct PacketHeader {
  int size;
  int groupId;
  int id;  // ��������ID (ex. 1=�α���, 2=�̵���û)
};
