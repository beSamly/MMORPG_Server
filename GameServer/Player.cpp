#include "pch.h"
#include "Player.h"

void Player::Init() {}

void Player::Send(std::shared_ptr<SendBuffer> buffer)
{
    if (sptr<ClientSession> session = tcpSession.lock())
    {
        session->Send(buffer);
    }
    else
    {
        //[TODO] ERROR
    }
}

void Player::Update(float deltaTime) {}
