#include "pch.h"
#include <fstream>
#include "SkillInfoManager.h"
#include "PhysicsEngine.h"
#include "OperationCondition.h"
#include "Operation.h"
#include "simdjson.h"
#include "LogMacro.h"
#include "SkillInfo.h"

using namespace simdjson;

SkillInfo SkillInfoManager::GetSkillInfo(int skillIndex)
{
	auto iter = mapSkillInfo.find(skillIndex);
	if (iter != mapSkillInfo.end())
	{
		return iter->second;
	}
	else
	{
		return SkillInfo();
	}
}

void SkillInfoManager::LoadDataFromPath()
{
	simdjson::dom::element data;
	simdjson::dom::parser parser;
	JsonDataManager::ParseDataFromPath(data, parser);

	for (const dom::element& jsonSkillInfo : data)
	{
		SkillInfo skillInfo;

		skillInfo.skillIndex = jsonSkillInfo["SkillIndex"].get_int64();
		skillInfo.skillName = jsonSkillInfo["SkillName"].get_string().value();
		skillInfo.coolTime = jsonSkillInfo["CoolTime"].get_int64();
		skillInfo.duration = jsonSkillInfo["Duration"].get_int64();

		for (const dom::element& jsonOperationTime : jsonSkillInfo["OperationTime"])
		{
			int operationTime = jsonOperationTime.get_int64();
			skillInfo.operationTime.push_back(operationTime);
		}

		for (const dom::element& jsonOperation : jsonSkillInfo["OperationList"])
		{
			OperationInfo operationInfo;
			operationInfo.operationType = jsonOperation["OperationType"].get_string().value();
			operationInfo.operationValue = jsonOperation["OperationValue"].get_int64();

			skillInfo.opereationList.push_back(operationInfo);

			// �ϴ� ��� �� �ϴ� �ּ�ó��
			//auto& operationCondition = jsonOperation["OperationCondition"];
			//operationCondition["ConditionType"];
			//operationCondition["ConditionValue"];
		}

		mapSkillInfo[skillInfo.skillIndex] = skillInfo;
	}
}
