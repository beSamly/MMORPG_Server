#pragma once
#include "pch.h"
#include "ClientSession.h"

namespace
{
    typedef function<int(sptr<ClientSession>& session, BYTE* buffer, int32 len)> BasePacketProcessFunc;
    typedef function<bool(sptr<ClientSession>&)> Validator;

#define TO_BASE_PACKET_PROCESS_FUNC(FUNC) [&](sptr<ClientSession>& session, BYTE* buffer, int32 len) { return FUNC(session, buffer, len); }
#define TO_VALIDATOR(FUNC) [&](sptr<ClientSession>& session) { return FUNC(session); }
} // namespace

class INetworkController
{
private:
    vector<Validator> vecValidator;

public:
    virtual int Process(sptr<ClientSession>& session, BYTE* buffer, int32 len) abstract;
    void AddValidator(Validator validator) { vecValidator.push_back(validator); }
};
