#include "pch.h"
#include "OperationProcessController.h"
#include "Projectile.h"

#define TO_OPERATION_PROCESS_FUNC(FUNC) [&](sptr<Scene>& scene, TriggeredOperation& operation) { return FUNC(scene, operation); }

OperationProcessController::OperationProcessController() { mapProcessFunc[OperationType::LaunchProjectile] = TO_OPERATION_PROCESS_FUNC(ProcessLaunchProjectile); }

void OperationProcessController::ProcessOperation(sptr<Scene>& scene, TriggeredOperation& triggeredOperation)
{
    OperationType operationType = triggeredOperation.operation->operationType;
    auto iter = mapProcessFunc.find(operationType);

    if (iter != mapProcessFunc.end())
    {
        iter->second(scene, triggeredOperation);
    }
    else
    {
        LOG_ERROR("OperationProcessController has not process func for operation type " + std::to_string(operationType));
    }
}

void OperationProcessController::ProcessLaunchProjectile(sptr<Scene>& scene, TriggeredOperation& triggeredOperation)
{
    sptr<LaunchProjectileOperation> launchProjectileOperation = dynamic_pointer_cast<LaunchProjectileOperation>(triggeredOperation.operation);

    if (launchProjectileOperation == nullptr)
    {
        LOG_ERROR("Can not copnvert Operation to LaunchProjectileOperation");
        return;
    }

    sptr<Projectile> projectile = make_shared<Projectile>();
    projectile->SetMoveDirection(triggeredOperation.playerInput.direction);
    projectile->projectileId = launchProjectileOperation->projectileIndex + 10000000; // TODO
    projectile->projectileIndex = launchProjectileOperation->projectileIndex;
    projectile->speed = launchProjectileOperation->speed;
    projectile->maxRange = launchProjectileOperation->maxRange;
    projectile->onCollisionOperation = launchProjectileOperation->onCollisionOperation;

    scene->projectileManager->AddProjectile(projectile);

    //씬에 있는 유저에게 Broadcast
    
    //scene->Broadcast();

}