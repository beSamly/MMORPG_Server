#pragma once
#include "TransformEntity.h"
#include "InputController.h"
#include "StatController.h"
#include "SkillController.h"

class Monster : public TransformEntity
{
private:

public:
	uptr<InputController> inputController;
	//uptr<TransformEntity> transformController;
	uptr<StatController> statController;
	uptr<SkillController> skillController;
	int MonsterId;

public:
	Monster();
	void Init();

};
