#include "pch.h"
#include "OperationProcessController.h"
#include "Projectile.h"

#define TO_OPERATION_PROCESS_FUNC(FUNC) [&](sptr<Scene>& scene, TriggeredOperation& operation) { return FUNC(scene, operation); }

OperationProcessController::OperationProcessController()
{
	mapProcessFunc[OperationType::LaunchProjectile] = TO_OPERATION_PROCESS_FUNC(ProcessLaunchProjectile);
}

void OperationProcessController::ProcessOperation(sptr<Scene>& scene, TriggeredOperation& triggeredOperation)
{
	OperationType operationType = triggeredOperation.operation->operationType;
	auto iter = mapProcessFunc.find(operationType);

	if (iter != mapProcessFunc.end()) {
		iter->second(scene, triggeredOperation);
	}
	else {

		LOG_ERROR("OperationProcessController has not process func for operation type " + std::to_string(operationType));
	}
}

void OperationProcessController::ProcessLaunchProjectile(sptr<Scene>& scene, TriggeredOperation& operation)
{

	sptr<Projectile> projectile = make_shared<Projectile>();

	//scene->projectileManager->AddProjectile();

}