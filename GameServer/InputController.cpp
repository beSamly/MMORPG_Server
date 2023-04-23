#include "pch.h"
#include "InputController.h"

InputController::InputController()
{
    mapKeyPressed[KEY_INPUT::DOWN] = false;
    mapKeyPressed[KEY_INPUT::UP] = false;
    mapKeyPressed[KEY_INPUT::RIGHT] = false;
    mapKeyPressed[KEY_INPUT::LEFT] = false;
}

bool InputController::IsAnyKeyDown()
{
    for (const auto& [key, value] : mapKeyPressed)
    {
        if (value == true)
        {
            return true;
        }
    }
    return false;
}
