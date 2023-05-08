#include "pch.h"
#include "Player.h"
#include "StatController.h"
#include "PositionUpdate.pb.h"
#include <Packet.h>
#include "PacketDef.h"
#include "Logger.h"
#include "GameSystemConstant.h"

using GameSystemConstant::GRAVITY;
using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_POSITION;

Player::Player() : TransformEntity()
{
	// transformController = make_unique<TransformEntity>();
	statController = make_unique<StatController>();
	skillController = make_unique<SkillController>();
}

void Player::Init() {}

void Player::Send(std::shared_ptr<SendBuffer> buffer)
{
	if (sptr<ClientSession> session = tcpSession.lock())
	{
		session->Send(buffer);
	}
}

void Player::Send(Packet& packet)
{
	if (sptr<ClientSession> session = tcpSession.lock())
	{
		session->Send(packet.GetSendBuffer());
	}
	else
	{
		LOG_DEBUG("player has no tcp session");
		//[TODO] ERROR
	}
}

int Player::GetStat(STAT_TYPE statType)
{
	int statValue = 0;

	// BaseStat 계산
	statValue += statController->GetBaseStat(statType);
	// [TODO] 장비 등등 스텟 계산

	return statValue;
}

void Player::Update(float deltaTime)
{
	UpdatePosition(deltaTime);
	skillController->Update(deltaTime);
}

void Player::UpdatePosition(float deltaTime)
{
	Vector3 addPosition;

	int statValue = GetStat(STAT_TYPE::MOVE_SPEED);
	float moveSpeed = statValue * deltaTime;

	// 이동하는 방향으로 이동속도만큼 이동
	addPosition += (GetMoveDirection() * moveSpeed);

	//[TODO] 중력 - 일단 이동속도 만큼 중력 나중에 바꿔라
	addPosition += (Vector3(0.0f, -GRAVITY, 0.0f) * deltaTime);

	AddPosition(addPosition);
}

void Player::SendUpdatePosition()
{
	Vector3 position = GetPosition();
	Vector3 moveDirection = GetMoveDirection();

	Protocol::PositionUpdate positionUpdate;
	positionUpdate.mutable_position()->set_x(position.x);
	positionUpdate.mutable_position()->set_y(position.y);
	positionUpdate.mutable_position()->set_z(position.z);

	positionUpdate.mutable_movedirection()->set_x(moveDirection.x);
	positionUpdate.mutable_movedirection()->set_y(moveDirection.y);
	positionUpdate.mutable_movedirection()->set_z(moveDirection.z);

	Packet packet(PACKET_GROUP_ID::POSITION, PACKET_ID_POSITION::POSITION_UPDATE);
	packet.WriteData<Protocol::PositionUpdate>(positionUpdate);
	Send(packet.GetSendBuffer());
}
