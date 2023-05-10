#pragma once
#include "Player.h"
#include "Packet.h"

struct Request
{
	sptr<Player> from;
	sptr<Packet> packet;

	int GetRequestId() {
		return packet->GetId();
	}

	int GetRequestGroupId() {
		return packet->GetGroupId();
	}
};

