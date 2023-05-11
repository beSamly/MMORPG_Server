#include "pch.h"
#include "Projectile.h"
#include "GameSystemConstant.h"

using GameSystemConstant::GRAVITY;

Projectile::Projectile() : TransformEntity()
{
}

void Projectile::Init() {}

void Projectile::Update(float deltaTime) { UpdatePosition(deltaTime); }

void Projectile::UpdatePosition(float deltaTime)
{
    float moveSpeed = speed * deltaTime;

    // 이동하는 방향으로 이동속도만큼 이동
    AddPosition(GetMoveDirection() * moveSpeed);
}



