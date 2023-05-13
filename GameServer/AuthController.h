#pragma once
#include "IRequestController.h"
#include "PacketDef.h"
#include "Packet.h"
#include "Logger.h"
#include "GameSystem.h"

using PacketDef::REQ_ID_AUTH;

class AuthController : public IRequestController
{
private:
	sptr<GameSystem> gameSystem;
	sptr<DataSystem> dataSystem;

public:
	AuthController(sptr<GameSystem> gameSystem, sptr<DataSystem> paramDataSystem);
	//virtual int Process(sptr<Request>& request) override;

private:
	int Process_LOGIN_REQ(sptr<Request>& request);
    int Process_CLIENT_DISCONNECTED(sptr<Request>& request);
};
