#pragma once
#include "pch.h"
#include "ClientSession.h"

namespace
{
    typedef function<int(sptr<ClientSession>& session, BYTE* buffer, int32 len)> BasePacketProcessFunc;

#define TO_BASE_PACKET_PROCESS_FUNC(FUNC)                                                                                 \
    [&](sptr<ClientSession>& session, BYTE* buffer, int32 len) { return FUNC(session, buffer, len); }
} // namespace

class INetworkController
{
public:
    virtual int Process(sptr<ClientSession>& session, BYTE* buffer, int32 len) abstract;
};
