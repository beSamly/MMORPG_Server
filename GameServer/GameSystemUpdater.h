
#include "pch.h"
#include "Player.h"
#include "Scene.h"

class GameSystemUpdater
{
private:


public:
	GameSystemUpdater() {

	}

	void UpdateEachPlayer(float deltaTime, const sptr<Scene>& scene, const sptr<Player>& player, const vector<sptr<Player>>& others)
	{
		// �÷��̾� ������ ��ü ������Ʈ
		player->Update(deltaTime);

		//[TODO]
		float radius = 10.0f; // Unity�� this.GetComponent<SphereCollider>().radius ��

		// ������ �浹 ó��
		Vector3 currentPosition = player->GetPosition();
		Vector3 newPosition = scene->navigationMeshAgent->ResolveCollision(currentPosition, radius);
		player->SetPosition(newPosition);

		if (player->inputController->IsAnyKeyDown())
		{
			player->SendUpdatePosition();
		}

		queue<Operation> readyOperation = player->skillController->GetReadyOperation();

		while (!readyOperation.empty())
		{
			Operation& operation = readyOperation.front();


			//smt like operation->trigger()
			//operation.opereationType


			readyOperation.pop();
		}

	}
};