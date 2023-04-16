#pragma once
#include "INetworkController.h"
#include "Logger.h"
#include <PacketDef.h>
#include "GameSystem.h"

using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_INPUT;

class InputReqController : public INetworkController
{
private:
    sptr<GameSystem> gameSystem;
    sptr<Logger> logger;
    map<PACKET_ID_INPUT, BasePacketProcessFunc> mapProcessFunc;

public:
    InputReqController(sptr<GameSystem> gameSystem, sptr<Logger> logger);
    virtual int Process(sptr<ClientSession>& session, BYTE* buffer, int32 len) override;
    int ProcessInputMovement(sptr<ClientSession>& session, BYTE* buffer, int32 len);
};
