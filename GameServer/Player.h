#pragma once
#include "TransformEntity.h"
#include "InputController.h"
#include "ClientSession.h"
#include "StatController.h"
#include "SkillController.h"
#include "Packet.h"

class Player : public TransformEntity
{
private:
private:
	wptr<ClientSession> tcpSession;

public:
	// uptr<TransformEntity> transformController;
	uptr<StatController> statController;
	uptr<SkillController> skillController;
	string currentSceneName;
	int playerId;

public:
	Player();
	void Init();
	void SetSession(wptr<ClientSession> session) { tcpSession = session; }
	void Send(std::shared_ptr<SendBuffer> buffer);
	void Send(Packet& packet);
	void Update(float deltaTime);
	void UpdatePosition(float deltaTime);
	virtual TransformEntityType GetEntityType() { return TransformEntityType::TYPE_PLAYER; };
	virtual int GetEntityId() { return playerId; };

public:
	void SendUpdatePosition();
	int GetStat(STAT_TYPE statType);
};
