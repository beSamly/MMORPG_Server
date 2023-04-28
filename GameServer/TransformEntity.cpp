#include "pch.h"
#include "TransformEntity.h"

Vector3 TransformEntity::GetPosition() { return position; }

void TransformEntity::Update(float deltaTime)
{
	if (position == targetPosition) {
		return;
	}

	Vector3 directionToTarget = targetPosition - position;

	float moveSpeed = 1;
	//Vector3 moveVector = directionToTarget.Normalized() * moveSpeed * deltaTime;

	//float distanceToMove = moveVector.GetMagnitude();
	//float distanceToTarget = directionToTarget.GetMagnitude();

	//// �̵��Ϸ��� �Ÿ��� targetPosition���� ��ٸ� targetPosition�� �����ѰŴ�.
	//if (distanceToMove > distanceToTarget) {
	//    position = targetPosition;
	//}
	//else {
	//    position = position + moveVector;
	//}
}

bool TransformEntity::IsMoving()
{
	return position == targetPosition ? false : true;
}
