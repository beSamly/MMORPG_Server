#include "pch.h"
#include "OperationConditionHandler.h"



OperationConditionHandler::OperationConditionHandler()
{
	//mapHandler[OperationConditionType::MYSELF] = Myself;
}


vector<sptr<TransformEntity>> OperationConditionHandler::Get(OperationConditionType type, sptr<TransformEntity> owner, vector<sptr<TransformEntity>> other)
{
	if (!mapHandler.count(type)) {
		return vector<sptr<TransformEntity>>();
	}

	return mapHandler[type](owner, other);
}

vector<sptr<TransformEntity>> OperationConditionHandler::OperationConditionHandler::Myself(sptr<TransformEntity> owner, vector<sptr<TransformEntity>> other)
{
	return vector<sptr<TransformEntity>>();
}