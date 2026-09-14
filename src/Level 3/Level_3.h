/**
 * @file Level_3.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief i.e. main.cpp
 *        only start up, create Game and run
 */

#ifndef VACUOUSVALLEY_LEVEL_3_H
#define VACUOUSVALLEY_LEVEL_3_H

#pragma once
#include<memory>

class GameState;
class RenderSystem;
class InputSystem;
class PhysicsSystem;

class Level_3 {
private:
    std::unique_ptr<GameState> m_state;
    std::unique_ptr<RenderSystem> m_renderer;
    std::unique_ptr<InputSystem> m_input;
    std::unique_ptr<PhysicsSystem> m_physics;

    void _update(float deltaTime) const;

    void _render() const;

public:
    Level_3();

    ~Level_3();

    void run() const;
};


#endif //VACUOUSVALLEY_LEVEL_3_H
