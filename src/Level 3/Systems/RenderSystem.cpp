#include "RenderSystem.h"

#include "../Core/GameState.h"

RenderSystem::RenderSystem(GameState &state) : m_state(state) {
}

void RenderSystem::render() const {
    m_state.camera.target={.x = m_state.player.positionX, .y = m_state.player.positionY};
    _drawPerson();
    _drawFence();
    DrawRectangle(50,50,50,50,RED);
}

void RenderSystem::_drawPerson() const {
    DrawRectangle(m_state.player.positionX - m_state.player.width / 2,
                  m_state.player.positionY - m_state.player.height / 2,
                  m_state.player.width, m_state.player.height,WHITE);
}

void RenderSystem::_drawFence() const {
    for (const auto &fence:m_state.fences) {
        DrawCircle(fence.positionX,fence.positionY,fence.radius,fence.color);
    }
}
