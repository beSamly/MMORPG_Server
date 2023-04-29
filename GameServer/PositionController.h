#pragma once
#include "INetworkController.h"
#include "Logger.h"
#include <PacketDef.h>
#include "GameSystem.h"

using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_POSITION;

class PositionController : public INetworkController
{
private:
    sptr<GameSystem> gameSystem;
    map<PACKET_ID_POSITION, PlayerPacketProcessFunc> mapProcessFunc;

public:
    PositionController(sptr<GameSystem> gameSystem);
    virtual int Process(sptr<ClientSession>& session, BYTE* buffer, int32 len) override;
    int ProcessMoveReq(sptr<ClientSession>& session, sptr<Player>& player, BYTE* buffer, int32 len);
};
