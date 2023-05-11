#include "pch.h"
#include "ProjectileInfoManager.h"
#include "simdjson.h"
#include "LogMacro.h"

using namespace simdjson;

void ProjectileInfoManager::LoadJsonData()
{
	LoadProjectileInfo();
}

ProjectileInfo ProjectileInfoManager::GetProjectileInfo(int index)
{
	auto iter = mapProjectileInfo.find(index);
	if (iter != mapProjectileInfo.end())
	{
		return iter->second;
	}
	else
	{
		return ProjectileInfo();
	}
}

void ProjectileInfoManager::LoadProjectileInfo()
{
	simdjson::dom::parser parser;
	simdjson::dom::element data;

	auto error = parser.load(FILE_PATH).get(data);
	if (error) {
		LOG_ERROR(FILE_PATH + " Failed to parse");
		return;
	}

	for (const dom::element& jsonSkillInfo : data)
	{
		ProjectileInfo info;
		info.projectileIndex = jsonSkillInfo["ProjectileIndex"].get_int64();
		info.maxRange = jsonSkillInfo["MaxRange"].get_int64();
		info.speed = jsonSkillInfo["Speed"].get_int64();
		info.onCollision = jsonSkillInfo["OnCollision"].get_string().value();

		mapProjectileInfo[info.projectileIndex] = info;
	}
}