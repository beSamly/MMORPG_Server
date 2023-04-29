#pragma once
#include "INetworkController.h"
#include "PacketDef.h"
#include "Packet.h"
#include "Logger.h"
#include "GameSystem.h"

using PacketDef::PACKET_ID_AUTH;

class AuthController : public INetworkController
{
private:
    sptr<GameSystem> gameSystem;
    sptr<DataSystem> dataSystem;
    map<PACKET_ID_AUTH, BasePacketProcessFunc> mapProcessFunc;

public:
    AuthController(sptr<GameSystem> gameSystem, sptr<DataSystem> paramDataSystem);
    virtual int Process(sptr<ClientSession>& session, BYTE* buffer, int32 len) override;

private:
    int ProcessLoginReq(sptr<ClientSession>& session, BYTE* buffer, int32 len);
};
