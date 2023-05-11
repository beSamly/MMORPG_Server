#pragma once
#include "TransformEntity.h"
#include "Operation.h"

class Projectile : public TransformEntity
{
public:
    int projectileIndex;
    int projectileId;
    int speed;
    int maxRange;
    sptr<Operation> onCollisionOperation;

public:
    Projectile();
    void Init();
    void Update(float deltaTime);
    virtual TransformEntityType GetEntityType() { return TransformEntityType::TYPE_PROJECTILE; };
    virtual int GetEntityId() { return projectileId; };

private:
    void UpdatePosition(float deltaTime);
};
