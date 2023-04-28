#include "pch.h"
#include "OperationCondition.h"
#include "TransformEntity.h"


class OperationConditionHandler
{
	typedef function<vector<sptr<TransformEntity>>(sptr<TransformEntity>, vector<sptr<TransformEntity>>)> FuncHandler;

private:
	map<OperationConditionType, FuncHandler> mapHandler;

	vector<sptr<TransformEntity>> Myself(sptr<TransformEntity> owner, vector<TransformEntity> other);
public:
	OperationConditionHandler();

	vector<sptr<TransformEntity>> Get(OperationConditionType type, sptr<TransformEntity> owner, vector<sptr<TransformEntity>> other);

};