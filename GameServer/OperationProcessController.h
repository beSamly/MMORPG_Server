#pragma once
#include "Logger.h"
#include "IRequestController.h"
#include "Scene.h"


class OperationProcessController
{
	typedef function<void(sptr<Scene>&, TriggeredOperation&)> OperationProcessFunc;

private:
	map<int, OperationProcessFunc> mapProcessFunc;

public:
	OperationProcessController();
	void ProcessOperation(sptr<Scene>& scene, TriggeredOperation& operation);

private:
	void ProcessLaunchProjectile(sptr<Scene>& scene, TriggeredOperation& operation);

};
