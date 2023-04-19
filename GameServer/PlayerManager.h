#pragma once
#include "Player.h"
#include "ClientSession.h"

class PlayerManager
{
public:
	PlayerManager();

private:
	USE_LOCK;
	map<int, sptr<Player>> mapPlayer;
	int tempPlayerId = 1;

public:
	void AddPlayer(sptr<Player> client);
	sptr<Player> GetPlayer(int playerId);
	void RemovePlayer(int playerId);
	void Update();
};
