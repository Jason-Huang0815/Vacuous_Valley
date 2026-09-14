/**
 * @file RenderSystem.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief cover all the entities and items, drawing
 */

#ifndef VACUOUSVALLEY_RENDERSYSTEM_H
#define VACUOUSVALLEY_RENDERSYSTEM_H

#pragma once
#include<raylib.h>

class GameState;


class RenderSystem {
private:
    GameState &m_state;

    void _drawPerson() const;

    void _drawFence() const;

public:
    explicit RenderSystem(GameState &state);

    void render() const;
};


#endif //VACUOUSVALLEY_RENDERSYSTEM_H
