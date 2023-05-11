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
	std::string operationType;
	int operationValue;
	//OperationConditionInfo conditionInfo; //�ϴ� ��� �� ��
};

struct SkillInfo
{
	int skillIndex;
	std::string skillName;
	int coolTime;
	int duration;
	vector<int> operationTime;
	vector<OperationInfo> opereationList;
};
