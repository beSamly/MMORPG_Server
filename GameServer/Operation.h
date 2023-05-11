#pragma once
#include "OperationCondition.h"

enum OperationType : int
{
	PhysicalDamage = 1,
	PhysicalDamageR = 1,
	Operattion_Projectile,
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