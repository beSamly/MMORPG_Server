#include "pch.h"
#include "SkillFactory.h"
#include "Operation.h"
#include "SkillInfo.h"


#define TO_OPERATION_BUILD_FUNC(FUNC) [&](OperationInfo& operationInfo) -> sptr<Operation>{ return FUNC(operationInfo); }

SkillFactory::SkillFactory(sptr<SkillInfoManager> paramSkillInfoManager, sptr<ProjectileInfoManager> paramProjectileInfoManager)
	: skillInfoManager(paramSkillInfoManager), projectileInfoManager(paramProjectileInfoManager)
{
	mapOperationBuildFunc["LaunchProjectile"] = TO_OPERATION_BUILD_FUNC(BuildLaunchProjectileOperation);
	mapOperationBuildFunc["Default"] = TO_OPERATION_BUILD_FUNC(BuildDefaultOperation);
}


sptr<Skill> SkillFactory::GetSkill(int skillIndex)
{
	sptr<Skill> skill = make_shared<Skill>();

	// SKillInfo 로 부터 Skill 객체 세팅
	{
		SkillInfo skillInfo = skillInfoManager->GetSkillInfo(skillIndex);
		skill->skillIndex = skillInfo.skillIndex;
		skill->skillName = skillInfo.skillName;
		skill->coolTime = skillInfo.coolTime;
		skill->duration = skillInfo.duration;

		for (int& operationTime : skillInfo.operationTime) {
			skill->AddOperationTime(operationTime);
		}

		for (OperationInfo& operationInfo : skillInfo.opereationList) {

			sptr<Operation> operation = GetOperation(operationInfo);
			skill->AddOperation(operation);
		}
	}

	return skill;
}

sptr<Operation> SkillFactory::GetOperation(OperationInfo operationInfo)
{
	auto iter = mapOperationBuildFunc.find(operationInfo.operationType);
	if (iter != mapOperationBuildFunc.end()) {

		return iter->second(operationInfo);
	}
	else {
		return mapOperationBuildFunc["Default"](operationInfo);
	}
}

sptr<Operation> SkillFactory::BuildLaunchProjectileOperation(OperationInfo& operationInfo)
{
	sptr<LaunchProjectileOperation> operation = make_shared<LaunchProjectileOperation>();
	operation->operationValue = operationInfo.operationValue;
	operation->operationType = OperationType::LaunchProjectile;

	ProjectileInfo projectileInfo = projectileInfoManager->GetProjectileInfo(operationInfo.operationValue);
	operation->projectileIndex = projectileInfo.projectileIndex;
	operation->speed = projectileInfo.speed;
	operation->maxRange = projectileInfo.maxRange;
	operation->onCollisionOperation = GetOperation(projectileInfo.onCollisionOperation);

	return operation;
}

sptr<Operation> SkillFactory::BuildDefaultOperation(OperationInfo& operationInfo)
{

	sptr<Operation> operation = make_shared<Operation>();
	operation->operationValue = operationInfo.operationValue;
	operation->operationType = OperationType::NONE;

	return operation;
}

