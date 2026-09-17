/**
 * @file InputSystem.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief reading the keyboard input
 */

#ifndef VACUOUSVALLEY_INPUTSYSTEM_H
#define VACUOUSVALLEY_INPUTSYSTEM_H
#include<raylib.h>

#pragma once

class GameState;

class InputSystem {
private:
    GameState &m_state;

public:
    explicit InputSystem(GameState &state);

    void update() const;
};


#endif //VACUOUSVALLEY_INPUTSYSTEM_H
