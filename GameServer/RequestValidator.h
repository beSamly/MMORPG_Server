#pragma once
#include "pch.h"
#include "ClientSession.h"
#include "GameSystem.h"

namespace RequestValidator
{
	bool IsPlayerLoggedIn(sptr<ClientSession>& clientSession) { return true; }
	bool IsPlayerInScene(sptr<GameSystem>& gameSystem, sptr<ClientSession>& session)
	{
		return true;
	}

} // namespace RequestValidator
