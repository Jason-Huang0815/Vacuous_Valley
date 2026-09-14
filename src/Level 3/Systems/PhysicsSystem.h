/**
 * @file PhysicsSystem.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief move, collision, etc.
 */

#ifndef VACUOUSVALLEY_PHYSICSSYSTEM_H
#define VACUOUSVALLEY_PHYSICSSYSTEM_H

#pragma once
#include<raylib.h>

class GameState;

class PhysicsSystem {
private:
    GameState &m_state;

public:
    explicit PhysicsSystem(GameState &state);

    void update(float dt);
};


#endif //VACUOUSVALLEY_PHYSICSSYSTEM_H
