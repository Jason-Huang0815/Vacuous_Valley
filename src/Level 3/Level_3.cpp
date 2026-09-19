#include "Level_3.h"

#include "raylib.h"

#include"Core/GameState.h"
#include"Systems/InputSystem.h"
#include"Systems/RenderSystem.h"
#include"Systems/PhysicsSystem.h"

Level_3::Level_3() {
    m_state = std::make_unique<GameState>();
    m_renderer = std::make_unique<RenderSystem>(*m_state);
    m_input = std::make_unique<InputSystem>(*m_state);
    m_physics = std::make_unique<PhysicsSystem>(*m_state);
}

Level_3::~Level_3() {
}

void Level_3::run() const {
    m_state->initCamera();
    m_state->initFence();
    while (!WindowShouldClose()) {
        const float dt = GetFrameTime();
        _update(dt);
        _render();
    }
}

void Level_3::_update(const float deltaTime) const {
    m_input->update();
    m_physics->update(deltaTime);
}

void Level_3::_render() const {
    BeginDrawing();
    ClearBackground({.r = 20, .g = 20, .b = 20, .a = 255});
    BeginMode2D(m_state->camera);
    m_renderer->render();
    EndMode2D();
    EndDrawing();
}

/* TODO:
 * draw house
 * house interact UI
 * interact
 * draw blood
 */
