#include "pch.h"
#include "Player.h"
#include "StatController.h"
#include "PositionUpdate.pb.h"
#include <Packet.h>
#include "PacketDef.h"

using PacketDef::PACKET_GROUP_ID;
using PacketDef::PACKET_ID_GLOBAL;

void Player::Init()
{
    inputController = make_unique<InputController>();
    // transformController = make_unique<TransformEntity>();
    statController = make_unique<StatController>();
    skillController = make_unique<SkillController>();
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
    float movePosition = statValue * deltaTime;

    if (inputController->IsKeyDown(KEY_INPUT::UP))
    {
        addPosition += Vector3(0.0f, 0.0f, movePosition);
    }

    if (inputController->IsKeyDown(KEY_INPUT::DOWN))
    {
        addPosition += Vector3(0.0f, 0.0f, -movePosition);
    }

    if (inputController->IsKeyDown(KEY_INPUT::LEFT))
    {
        addPosition += Vector3(-movePosition, 0.0f, 0.0f);
    }

    if (inputController->IsKeyDown(KEY_INPUT::RIGHT))
    {
        addPosition += Vector3(movePosition, 0.0f, 0.0f);
    }

    // 중력
    //addPosition += Vector3(0.0f, -movePosition, 0.0f);

    AddPosition(addPosition);
}

void Player::SendUpdatePosition()
{
    Vector3 position = GetPosition();

    Protocol::PositionUpdate positionUpdate;
    positionUpdate.mutable_position()->set_x(position.x);
    positionUpdate.mutable_position()->set_y(position.y);
    positionUpdate.mutable_position()->set_z(position.z);

    Packet packet(PACKET_GROUP_ID::GLOBAL, PACKET_ID_GLOBAL::POSITION_UPDATE);
    packet.WriteData<Protocol::PositionUpdate>(positionUpdate);
    Send(packet.GetSendBuffer());
}
