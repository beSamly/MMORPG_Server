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

}



