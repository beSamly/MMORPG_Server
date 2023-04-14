#pragma once
#include "TransformController.h"
#include "InputController.h"

class Player
{
private:
	int playerId;

private:
	sptr<InputController> inputController;
	sptr<TransformController> transformController;

public:
	template<class T>
	std::shared_ptr<T> GetController();

	template<>
	sptr<InputController> GetController() { return inputController; };
	sptr<TransformController> GetController() { return transformController; };

public:
	Player() { Init(); };
	void Init();
	int GetPlayerId() { return playerId; }
	void SetPlayerId(int id) { playerId = id; }

	void Update(float deltaTime);

};
