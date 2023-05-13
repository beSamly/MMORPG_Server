#include "pch.h"
#include "NPC.h"
#include "GameSystemConstant.h"

using GameSystemConstant::GRAVITY;

NPC::NPC() : TransformEntity()
{
    // transformController = make_unique<TransformEntity>();
    statController = make_unique<StatController>();
    skillController = make_unique<SkillController>();
    patrolController = make_unique<PatrolController>();
}

void NPC::Init() {}

int NPC::GetStat(STAT_TYPE statType)
{
    int statValue = 0;

    // BaseStat ���
    statValue += statController->GetBaseStat(statType);
    // [TODO] ��� ��� ���� ���

    return statValue;
}

void NPC::Update(float deltaTime)
{
    UpdatePosition(deltaTime);
    patrolController->Update(deltaTime);
}

void NPC::UpdatePosition(float deltaTime)
{
    Vector3 addPosition;

    int statValue = GetStat(STAT_TYPE::MOVE_SPEED);

    // �̵��ϴ� �������� �̵��ӵ���ŭ �̵�
    addPosition += (GetMoveDirection() * statValue * deltaTime);

    //[TODO] �߷� - �ϴ� �̵��ӵ� ��ŭ �߷� ���߿� �ٲ��
    addPosition += (Vector3(0.0f, -GRAVITY, 0.0f) * deltaTime);

    AddPosition(addPosition);
}

void NPC::UpdateMoveDirection(float deltaTime) {}
