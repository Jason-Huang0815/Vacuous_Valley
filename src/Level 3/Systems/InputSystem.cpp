#include "InputSystem.h"

#include "../Core/GameState.h"

InputSystem::InputSystem(GameState &state) : m_state(state) {
}

void InputSystem::update() const {
    if (IsKeyDown(KEY_A)) {
        m_state.player.positionX-=10;
    }

    if (IsKeyDown((KEY_W))) {
        m_state.player.positionY-=10;
    }

    if (IsKeyDown(KEY_S)) {
        m_state.player.positionY+=10;
    }

    if (IsKeyDown(KEY_D)) {
        m_state.player.positionX+=10;
    }
}
