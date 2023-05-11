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

    // �̵��ϴ� �������� �̵��ӵ���ŭ �̵�
    AddPosition(GetMoveDirection() * moveSpeed);
}



