#pragma once
#include "TransformController.h"
#include "InputController.h"
#include "ClientSession.h"
#include "StatController.h"

class Player
{
private:

private:
    wptr<ClientSession> tcpSession;

public:
    uptr<InputController> inputController;
    uptr<TransformController> transformController;
    uptr<StatController> statController;
    string currentSceneName;
    int playerId;


public:
    Player() { Init(); };
    void Init();
    void SetSession(wptr<ClientSession> session) { tcpSession = session; }
    void Send(std::shared_ptr<SendBuffer> buffer);
    void Update(float deltaTime);

public:
    void SendUpdatePosition();
    int GetStat(STAT_TYPE statType);

private:
    void UpdatePosition(float deltaTime);
};
