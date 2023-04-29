#pragma once
#include "PhysicsEngine.h"

using PhysicsEngine::Vector3;

class InputController
{
private:
    Vector3 moveDirection;

public:
    InputController();
    Vector3 GetMoveDirection() { return moveDirection; }

    void SetMoveDirection(Vector3 direction)
    {
        direction.Normalize();
        moveDirection = direction;
    };
};
