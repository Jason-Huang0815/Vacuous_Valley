#include "RenderSystem.h"

#include "../Core/GameState.h"

RenderSystem::RenderSystem(GameState &state) : m_state(state) {
}

void RenderSystem::render() const {
    _drawPerson();
    _drawFence();
}

void RenderSystem::_drawPerson() const {
    DrawRectangle(m_state.player.positionX - m_state.player.width / 2,
                  m_state.player.positionY - m_state.player.height / 2,
                  m_state.player.width, m_state.player.height,WHITE);
}

void RenderSystem::_drawFence() const {
}
