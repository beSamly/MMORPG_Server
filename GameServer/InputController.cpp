#include "pch.h"
#include "InputController.h"

void InputController::HandleInput(KEY_INPUT input)
{
	keyInput[(int)input] = true;
}

bool InputController::IsKeyDown(KEY_INPUT input)
{
	return keyInput[(int)input];
}
