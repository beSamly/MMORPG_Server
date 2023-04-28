#include "pch.h"
#include <fstream>
#include "SkillDataManager.h"
#include "PhysicsEngine.h"
#include "rapidjson/document.h"
#include "OperationCondition.h"
#include "Operation.h"

using std::ifstream;
using std::istreambuf_iterator;
using namespace rapidjson;

void SkillDataManager::LoadJsonData()
{
	LoadSkillData();
}

Skill SkillDataManager::GetSkillData(int skillIndex)
{
	auto iter = mapSkillData.find(skillIndex);
	if (iter != mapSkillData.end())
	{
		return iter->second;
	}
	else
	{
		return Skill();
	}
}

void SkillDataManager::LoadSkillData()
{
	// Open the file
	ifstream file(FILE_PATH);

	string jsonStr((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

	Document d;

	d.Parse(jsonStr.c_str());

	// Check for parse errors
	if (d.HasParseError())
	{
		std::cerr << "Error parsing JSON: " << d.GetParseError() << std::endl;
		assert(false);
		return;
	}

	const auto& listSkillData = d.GetArray();
	for (auto& jsonSkillData : listSkillData)
	{
		Skill skillData;

		skillData.skillIndex = jsonSkillData["SkillIndex"].GetInt();
		skillData.skillName = jsonSkillData["SkillName"].GetString();
		skillData.coolTime = jsonSkillData["CoolTime"].GetInt();
		skillData.duration = jsonSkillData["Duration"].GetInt();

		const auto& listOperation = jsonSkillData["OperationList"].GetArray();
		for (auto& jsonOperation : listOperation)
		{
                    /*Operation operation;
                    operation.opereationType = jsonOperation["OperationType"].GetString();
                    operation.operationValue = jsonOperation["OperationValue"].GetInt();

                    const auto& jsonOperationCondition = jsonOperation["OperationCondition"];
                    OperationCondition condition;
                    condition.conditionType = jsonOperationCondition["ConditionType"].GetString();
                    condition.conditionValue = jsonOperationCondition["ConditionValue"].GetInt();

                    operation.condition = condition;

                    skillData.AddOperation(operation);*/
		}

		mapSkillData[skillData.skillIndex] = skillData;
	}

	return;
}
