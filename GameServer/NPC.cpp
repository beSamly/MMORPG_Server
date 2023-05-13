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

    // BaseStat 계산
    statValue += statController->GetBaseStat(statType);
    // [TODO] 장비 등등 스텟 계산

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

    // 이동하는 방향으로 이동속도만큼 이동
    addPosition += (GetMoveDirection() * statValue * deltaTime);

    //[TODO] 중력 - 일단 이동속도 만큼 중력 나중에 바꿔라
    addPosition += (Vector3(0.0f, -GRAVITY, 0.0f) * deltaTime);

    AddPosition(addPosition);
}

void NPC::UpdateMoveDirection(float deltaTime) {}
