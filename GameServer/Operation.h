#pragma once
#include "OperationCondition.h"
#include "OperationType.h"

class Operation
{
public:
	OperationType operationType;
	int operationValue;

	//OperationCondition condition;
	/*vector<> vecOperation;
	vector<> vecOperationTime;*/

};

class LaunchProjectileOperation :public Operation
{
public:
	int projectileIndex;
	int maxRange;
	int speed;
	sptr<Operation> onCollisionOperation;
};