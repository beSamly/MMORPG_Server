#pragma once

enum OperationConditionType : int
{
	MYSELF = 1,
	AROUND_ME,
	OTHER,
};

class OperationCondition
{
public:
	int conditionType;
	int conditionValue;

	/*vector<> vecOperation;
	vector<> vecOperationTime;*/

};