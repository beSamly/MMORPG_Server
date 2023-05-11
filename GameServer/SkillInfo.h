#pragma once
#include "pch.h"
#include <string>

struct OperationConditionInfo
{
	int conditionType;
	int conditionValue;
};

struct OperationInfo
{
	string operationType;
	int operationValue;
	OperationConditionInfo conditionInfo;
};

struct SkillInfo
{
	int skillIndex;
	string skillName;
	int coolTime;
	int duration;
	vector<int> operationTime;
	vector<OperationInfo> opereationList;
};
