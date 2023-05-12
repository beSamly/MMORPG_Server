#include "pch.h"
#include "ProjectileInfoManager.h"
#include "simdjson.h"
#include "LogMacro.h"

using namespace simdjson;

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

void ProjectileInfoManager::LoadDataFromPath()
{
	simdjson::dom::element data;
	simdjson::dom::parser parser;
	JsonDataManager::ParseDataFromPath(data, parser);

	for (const dom::element& jsonProjectileInfo : data)
	{
		ProjectileInfo info;
		info.projectileIndex = jsonProjectileInfo["ProjectileIndex"].get_int64();
		info.maxRange = jsonProjectileInfo["MaxRange"].get_int64();
		info.speed = jsonProjectileInfo["Speed"].get_int64();

		const auto& onCollisionOperation = jsonProjectileInfo["OnCollisionOperation"];

		info.onCollisionOperation.operationType = onCollisionOperation["OperationType"].get_string().value();
		info.onCollisionOperation.operationValue = onCollisionOperation["OperationValue"].get_int64();

		mapProjectileInfo[info.projectileIndex] = info;
	}
}