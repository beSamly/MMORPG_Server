#pragma once

enum MOVEMENT_INPUT : int
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

class InputController
{
    const static int TOTAL_KEY_INPUT = 4;

private:
    bool keyInput[TOTAL_KEY_INPUT] = {
        false,
    };

public:
    void HandleInputMovement(MOVEMENT_INPUT input, bool value) { keyInput[input] = value; };
    bool IsKeyDown(MOVEMENT_INPUT input) { return keyInput[static_cast<int>(input)]; };
};
