#pragma once
#include "TransformController.h"
#include "InputController.h"
#include "ClientSession.h"

class Player
{
private:
	int playerId;

private:
	wptr<ClientSession> tcpSession;
	sptr<InputController> inputController;
	sptr<TransformController> transformController;
	sptr<StatController> statController;
	string currentSceneName;

public:
	Player() { Init(); };
	void Init();
	void Send(std::shared_ptr<SendBuffer> buffer);
	int GetPlayerId() { return playerId; }
	void SetPlayerId(int id) { playerId = id; }
	string GetCurrentSceneName() { return currentSceneName; }
	void SetCurrentSceneName(string sceneName) { currentSceneName = sceneName; }
	void Update(float deltaTime);

public:
	template <class T>
	std::shared_ptr<T> GetController();

	template <>
	sptr<InputController> GetController()
	{
		return inputController;
	};
	template <>
	sptr<TransformController> GetController()
	{
		return transformController;
	};
};
