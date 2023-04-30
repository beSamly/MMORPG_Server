#include "pch.h"
#include "PlayerManager.h"
#include "Player.h"

void PlayerManager::AddPlayer(sptr<Player> player)
{
    WRITE_LOCK;
    mapPlayer.emplace(tempPlayerId, player);
    tempPlayerId++;
    return;
}

sptr<Player> PlayerManager::GetPlayer(int playerId)
{
    map<int, sptr<Player>>::iterator iter = mapPlayer.find(playerId);
    if (iter != mapPlayer.end())
    {
        return iter->second;
    }
    else
    {
        return nullptr;
    }
}

vector<sptr<Player>> PlayerManager::GetPlayersById(std::set<int> playerIds)
{
    vector<sptr<Player>> players;
    for (const int& playerId : playerIds)
    {
        sptr<Player> player = GetPlayer(playerId);

        if (player == nullptr)
        {
            //!! ERROR
            LOG_ERROR("PlayerManager has no player for playerId" + playerId);
            continue;
        }

        players.push_back(player);
    }

    return players;
}

void PlayerManager::RemovePlayer(int playerId) { mapPlayer.erase(playerId); }

void PlayerManager::Update()
{
    /*Vector<PlayerRef> copiedPlayers;
    {
                    WRITE_LOCK;
                    for (auto const& [accountId, player] : *_players) {
                                    copiedPlayers.push_back(player);
                    }
    }

    for (auto& player : copiedPlayers) {
                    player->Update();
    }*/
}

PlayerManager::PlayerManager()
{
    /*auto job = MakeShared<Job>([this]() {
                    this->Update();
    });
    Scheduler::SetInterval(job);*/
}