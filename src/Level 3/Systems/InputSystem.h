/**
 * @file InputSystem.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief reading the keyboard input
 */

#ifndef VACUOUSVALLEY_INPUTSYSTEM_H
#define VACUOUSVALLEY_INPUTSYSTEM_H

#pragma once

class GameState;

class InputSystem {
private:
    GameState &m_state;

public:
    explicit InputSystem(GameState &state);

    void update();
};


#endif //VACUOUSVALLEY_INPUTSYSTEM_H
