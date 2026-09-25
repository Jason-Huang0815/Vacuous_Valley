#include "InputSystem.h"

#include "../Core/GameState.h"
#include "../Core/GameRules.h"

InputSystem::InputSystem(GameState &state) : m_state(state) {
}

void InputSystem::update() const {
    if (m_state.states.top() != State::ENTRE_HOUSE) {
        if (IsKeyDown(KEY_A)) {
            m_state.player.positionX -= 10;
        }

        if (IsKeyDown((KEY_W))) {
            m_state.player.positionY -= 10;
        }

        if (IsKeyDown(KEY_S)) {
            m_state.player.positionY += 10;
        }

        if (IsKeyDown(KEY_D)) {
            m_state.player.positionX += 10;
        }
    }

    if (IsKeyDown(KEY_R) && m_state.states.top() == State::ENTRE_HOUSE) {
        GameRules::exitRoom(m_state);
    }
}
