#include "pch.h"
#include "OperationHandler.h"



OperationHandler::OperationHandler()
{
	//mapHandler[OperationConditionType::MYSELF] = Myself;
}

void OperationHandler::Apply(sptr<Scene>& scene, Operation& operation, sptr<Player>& owner, vector<sptr<Player>>& target)
{
	if (!mapHandler.count(type)) {
		//ERROR
		return;
	}

	return mapHandler[type](scene, operation, owner, target);
}

void OperationHandler::DoPhysicalDamage(sptr<Scene>& scene, Operation& operation, sptr<Player>& owner, vector<sptr<Player>>& target)
{

}

