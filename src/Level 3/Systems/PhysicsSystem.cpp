#include "PhysicsSystem.h"
#include "../Core/GameState.h"
#include<raymath.h>

PhysicsSystem::PhysicsSystem(GameState &state) : m_state(state) {
}

void PhysicsSystem::update(float dt) const {
    _checkFenceCollision();
    _checkHouseCollision();
}

void PhysicsSystem::_checkFenceCollision() const {
    for (const auto &fence: m_state.fences) {
        const Vector2 closest = {
            .x = Clamp(fence.positionX, m_state.player.positionX - m_state.player.width / 2,
                       m_state.player.positionX + m_state.player.width / 2),
            .y = Clamp(fence.positionY, m_state.player.positionY - m_state.player.height / 2,
                       m_state.player.positionY + m_state.player.height / 2)
        };
        const Vector2 difference = Vector2Subtract(closest, {.x = fence.positionX, .y = fence.positionY});
        const float distance = Vector2Length(difference);

        if (distance >= fence.radius) {
            continue;
        }

        const float penetration = fence.radius - distance;
        const Vector2 push = Vector2Scale(difference, penetration / distance);

        m_state.player.positionX += push.x;
        m_state.player.positionY += push.y;
    }
}

void PhysicsSystem::_checkHouseCollision() const {
    const Rectangle player = {
        .x = m_state.player.positionX - m_state.player.width / 2,
        .y = m_state.player.positionY - m_state.player.height / 2,
        .width = (float) m_state.player.width, .height = (float) m_state.player.height,
    };

    for (const auto &house: m_state.houses) {
        const Rectangle building = {
            .x = house.building.positionX, .y = house.building.positionY, .width = (float) house.building.size,
            .height = (float) house.building.size
        };

        if (CheckCollisionRecs(player, building)) {
            const float overlapLeft = (m_state.player.positionX + m_state.player.width / 2) - house.building.positionX;
            const float overlapRight = (house.building.positionX + house.building.size) - (
                                           m_state.player.positionX - m_state.player.width / 2);
            const float overlapTop = (m_state.player.positionY + m_state.player.height / 2) - house.building.positionY;
            const float overlapBottom = (house.building.positionY + house.building.size) - (
                                            m_state.player.positionY - m_state.player.height / 2);

            const float minX = (overlapLeft < overlapRight) ? overlapLeft : -overlapRight;
            const float minY = (overlapTop < overlapBottom) ? overlapTop : -overlapBottom;

            if (std::abs(minX) < std::abs(minY)) {
                m_state.player.positionX -= minX;
            } else {
                m_state.player.positionY -= minY;
            }
        }
    }
}