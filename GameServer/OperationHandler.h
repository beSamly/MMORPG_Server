#include "pch.h"
#include "OperationCondition.h"
#include "TransformEntity.h"
#include "Operation.h"
#include "Player.h"
#include "Scene.h"

class OperationHandler
{
	typedef function<void(sptr<Scene>&, Operation&, sptr<Player>&, vector<sptr<Player>>&)> FuncHandler;

private:
	map<OperationType, FuncHandler> mapHandler;

	void DoPhysicalDamage(sptr<Scene>& scene, Operation& operation, sptr<Player>& owner, vector<sptr<Player>>& target);
public:
	OperationHandler();

	void Apply(sptr<Scene>& scene, Operation& operation, sptr<Player>& owner, vector<sptr<Player>>& target);

};