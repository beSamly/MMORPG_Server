#pragma once

const int TOTAL_KEY_INPUT = 4;

class InputController
{
	enum KEY_INPUT : int {
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	bool keyInput[TOTAL_KEY_INPUT] = { false, };

public:

	void HandleInput(KEY_INPUT input);

	bool IsKeyDown(KEY_INPUT input);
};

