#include "pch.h"
#include "ClientManager.h"

void ClientManager::AddClient(sptr<ClientSession> client)
{
    WRITE_LOCK;
    int proxyId = tempProxyId;
    clientMap->emplace(proxyId, client);
    tempProxyId++;
    return;
}

void ClientManager::RemoveClient(int playerId) { clientMap->erase(playerId); }

void ClientManager::Update()
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

ClientManager::ClientManager()
{
    /*auto job = MakeShared<Job>([this]() {
            this->Update();
    });
    Scheduler::SetInterval(job);*/
}