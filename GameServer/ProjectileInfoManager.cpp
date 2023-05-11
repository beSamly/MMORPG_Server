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

	for (const dom::element& jsonProjectileInfo : data)
	{
		ProjectileInfo info;
		info.projectileIndex = jsonProjectileInfo["ProjectileIndex"].get_int64();
		info.maxRange = jsonProjectileInfo["MaxRange"].get_int64();
		info.speed = jsonProjectileInfo["Speed"].get_int64();

		const auto& onCollisionOperation = jsonProjectileInfo["OnCollisionOperation"];

		info.onCollisionOperation.operationType = onCollisionOperation["OperationType"];
		info.onCollisionOperation.operationValue = onCollisionOperation["OperationValue"];

		/*
		  "ProjectileIndex": 1,
		"MaxRange": 1000,
		"Speed": 10,
		"ProjectileType": "Penetraion",
		"OnCollisionOperation": {
			"OperationType": "PhysicalDamageR",
			"OperationValue": 10
		}
		*/

		mapProjectileInfo[info.projectileIndex] = info;
	}
}