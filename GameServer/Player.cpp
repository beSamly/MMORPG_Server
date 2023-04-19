#include "pch.h"
#include "Player.h"
#include "StatController.h"

void Player::Init() {
	inputController = make_shared<InputController>();
	transformController = make_shared<TransformController>();
	statController = make_shared<StatController>();
}

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

void Player::Update(float deltaTime) {

	inputController->IsKeyDown(MOVEMENT_INPUT::DOWN);

}
