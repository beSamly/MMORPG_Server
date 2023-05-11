#pragma once
#include "SkillInfoManager.h"
#include "ProjectileInfoManager.h"
#include "Skill.h"

class SkillFactory
{
private:
	typedef function<sptr<Operation>(OperationInfo&)> OperationBuildFunc;
	sptr<SkillInfoManager> skillInfoManager;
	sptr<ProjectileInfoManager> projectileInfoManager;
	map<string, OperationBuildFunc> mapOperationBuildFunc;

public:
	SkillFactory(sptr<SkillInfoManager> paramSkillInfoManager, sptr<ProjectileInfoManager> paramProjectileInfoManager);
	sptr<Skill> GetSkill(int skillIndex);
	sptr<Operation> GetOperation(OperationInfo operationInfo);


private:
	sptr<Operation> BuildLaunchProjectileOperation(OperationInfo& operationInfo);
	sptr<Operation> BuildDefaultOperation(OperationInfo& operationInfo);
};
