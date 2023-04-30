#include "pch.h"
#include "TransformEntity.h"

Vector3 TransformEntity::GetPosition() { return position; }

void TransformEntity::Update(float deltaTime)
{

}

Vector3 TransformEntity::GetMoveDirection() { return moveDirection; }

void TransformEntity::SetMoveDirection(Vector3 direction)
{
    direction.Normalize();
    moveDirection = direction;
};