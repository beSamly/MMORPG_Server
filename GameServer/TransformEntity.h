#pragma once
#include "PhysicsEngine.h"

using PhysicsEngine::Vector3;

enum TransformEntityType : int
{
    TYPE_NONE = 0,
    TYPE_PLAYER,
    TYPE_NPC,
    TYPE_PROJECTILE
};

class TransformEntity
{
private:
    Vector3 position;
    Vector3 moveDirection;
    float radius = 0.5f;

public:
    TransformEntity(){};
    Vector3 GetPosition();
    void SetPosition(Vector3& newPositoin)
    {
        position = newPositoin;
    };

    void SetPosition(Vector3&& newPositoin) { position = newPositoin; };
    void AddPosition(Vector3 addPositoin) { position += addPositoin; };
    float GetRadius() { return radius; }
    void Update(float deltaTime);
    // bool IsMoving();

    Vector3 GetMoveDirection();
    void SetMoveDirection(Vector3 direction);
    virtual TransformEntityType GetEntityType() abstract;
    virtual int GetEntityId() abstract;
};
