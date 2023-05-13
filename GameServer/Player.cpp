#include "pch.h"
#include "Player.h"
#include "StatController.h"
#include "POSITION_UPDATE.pb.h"
#include <Packet.h>
#include "PacketDef.h"
#include "Logger.h"
#include "GameSystemConstant.h"

using GameSystemConstant::GRAVITY;
using namespace PacketDef;

Player::Player() : TransformEntity()
{
    // transformController = make_unique<TransformEntity>();
    statController = make_unique<StatController>();
    skillController = make_unique<SkillController>();
}

void Player::Init() {}

void Player::Send(sptr<Packet>& packet)
{
    if (sptr<ClientSession> session = tcpSession.lock())
    {
        session->Send(packet);
    }
    else
    {
        isDisconnected = true;
        LOG_DEBUG("player has no tcp session");
        //[TODO] ERROR
    }
}

void Player::Send(Packet& packet)
{
    if (sptr<ClientSession> session = tcpSession.lock())
    {
        session->Send(packet);
    }
    else
    {
        isDisconnected = true;
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
