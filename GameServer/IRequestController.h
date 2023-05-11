#pragma once
#include "pch.h"
#include "ClientSession.h"
#include "Player.h"
#include "Request.h"

namespace
{
	typedef function<int(sptr<ClientSession>& session, BYTE* buffer, int32 len)> BasePacketProcessFunc;
	typedef function<int(sptr<ClientSession>& session, sptr<Player>& player, BYTE* buffer, int32 len)> PlayerPacketProcessFunc;
	typedef function<int(sptr<Request>&)> RequestProcessFunc;
	typedef function<bool(sptr<ClientSession>&)> Validator;

#define TO_BASE_PACKET_PROCESS_FUNC(FUNC) [&](sptr<ClientSession>& session, BYTE* buffer, int32 len) { return FUNC(session, buffer, len); }
#define TO_REQUEST_PROCESS_FUNC(FUNC) [&](sptr<Request>& request) { return FUNC(request); }
#define TO_PLAYER_PACKET_PROCESS_FUNC(FUNC) [&](sptr<ClientSession>& session, sptr<Player>& player, BYTE* buffer, int32 len) { return FUNC(session, player, buffer, len); }
#define TO_VALIDATOR(FUNC) [&](sptr<ClientSession>& session) { return FUNC(session); }
} // namespace

class IRequestController
{
private:
	vector<Validator> vecValidator;
	map<int, RequestProcessFunc> mapProcessFunc;

public:
	void AddValidator(Validator validator) { vecValidator.push_back(validator); }
	void AddProcessFunc(int requestId, RequestProcessFunc func) { mapProcessFunc[requestId] = func; }

	virtual int Process(sptr<Request>& request)
	{

		RequestProcessFunc func = mapProcessFunc[request->packet->GetId()];

		if (func)
		{
			return func(request);
		}
		else
		{
			LOG_ERROR("IRequestController has no process function for groupId = " + std::to_string(request->packet->GetGroupId()) + " requestId =  " + std::to_string(request->packet->GetId()));
		}
	};
};
