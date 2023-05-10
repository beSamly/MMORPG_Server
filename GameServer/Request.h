#pragma once
#include "Player.h"
#include "Packet.h"

struct Request
{
	sptr<Player> player;
	sptr<ClientSession> session;
	sptr<Packet> packet;

	int GetRequestId() {
		return packet->GetId();
	}

	int GetRequestGroupId() {
		return packet->GetGroupId();
	}
};

