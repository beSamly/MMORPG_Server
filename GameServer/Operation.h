#include "OperationCondition.h"

enum OperationType : int
{
	PhysicalDamage = 1,
	Projectile,
};

class Operation
{
public:
	OperationType opereationType;
	int operationValue;

	OperationCondition condition;
	/*vector<> vecOperation;
	vector<> vecOperationTime;*/

};