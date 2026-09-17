#include "PhysicsSystem.h"
#include "../Core/GameState.h"
#include<raymath.h>

PhysicsSystem::PhysicsSystem(GameState &state) : m_state(state) {
}

void PhysicsSystem::update(float dt) const {
    _checkFecnceCollision();
}

void PhysicsSystem::_checkFecnceCollision() const {
    for (const auto &fence: m_state.fences) {
        const Vector2 closest = {
            .x = Clamp(fence.positionX, m_state.player.positionX - m_state.player.width / 2,
                       m_state.player.positionX + m_state.player.width / 2),
            .y = Clamp(fence.positionY, m_state.player.positionY - m_state.player.height / 2,
                       m_state.player.positionY + m_state.player.height / 2)
        };
        const Vector2 difference=Vector2Subtract(closest,{.x = fence.positionX,.y = fence.positionY});
        const float distance=Vector2Length(difference);
        if (distance>=fence.radius) {
            continue;
        }
        const float penetration=fence.radius-distance;
        const Vector2 push=Vector2Scale(difference,penetration/distance);
        m_state.player.positionX+=push.x;
        m_state.player.positionY+=push.y;
    }
}
