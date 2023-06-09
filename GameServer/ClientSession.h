#pragma once
#include "pch.h"
#include "AsioSession.h"
#include <asio/io_context.hpp>
#include "Packet.h"

/*-----------------
                                ClientSession
------------------*/
class ClientSession : public AsioSession
{
public:
    ClientSession(sptr<asio::io_context> context);
    virtual ~ClientSession();

private:
public:
    bool isAuthenticated = false;
    int clientId = 0;
    int playerId = 0;

    void Send(sptr<Packet>& packet);
    void Send(Packet& packet);
};
