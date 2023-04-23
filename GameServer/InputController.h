#pragma once

enum KEY_INPUT : int
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

class InputController
{
private:
    map<int, bool> mapKeyPressed;

public:
    InputController();
    void SetKeyPressed(KEY_INPUT input, bool value) { mapKeyPressed[input] = value; };
    bool IsKeyDown(KEY_INPUT input) { return mapKeyPressed[static_cast<int>(input)]; };
    bool IsAnyKeyDown();
};
