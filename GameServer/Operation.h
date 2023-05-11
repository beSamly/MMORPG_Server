#pragma once
#include "OperationCondition.h"

enum OperationType : int
{
	PhysicalDamage = 1,
	PhysicalDamageR,
	LaunchProjectile,
};

class Operation
{
public:
	OperationType opereationType;
	int operationValue;
	int operationDuration;

	OperationCondition condition;
	/*vector<> vecOperation;
	vector<> vecOperationTime;*/

};