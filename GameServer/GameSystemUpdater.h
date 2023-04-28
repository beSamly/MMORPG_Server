#pragma once
#include "pch.h"
#include "Player.h"
#include "Scene.h"

class GameSystemUpdater
{
private:
    float lastChecked = 0.0f;
    float elapsedTime = 0.0f;

public:
    GameSystemUpdater() {}

    void UpdateEachPlayer(float deltaTime, const sptr<Scene>& scene, const sptr<Player>& player, const vector<sptr<Player>>& others)
    {

        //[TEST]
        elapsedTime += deltaTime;

        // 플레이어 포지션 객체 업데이트
        player->Update(deltaTime);

        //[TODO]
        float radius = 0.5f; // Unity의 this.GetComponent<SphereCollider>().radius 값

        // 지형과 충돌 처리
        Vector3 currentPosition = player->GetPosition();
        Vector3 newPosition = scene->navigationMeshAgent->ResolveCollision(currentPosition, radius);
        player->SetPosition(newPosition);

        if (elapsedTime - lastChecked > 2)
        {
            player->SendUpdatePosition();
            lastChecked = elapsedTime;
        }

        /*if (player->inputController->IsAnyKeyDown())
        {
            player->SendUpdatePosition();
        }*/

        // queue<Operation> readyOperation = player->skillController->GetReadyOperation();

        // while (!readyOperation.empty())
        //{
        //	Operation& operation = readyOperation.front();

        //	//smt like operation->trigger()
        //	//operation.opereationType

        //	readyOperation.pop();
        //}
    }
};