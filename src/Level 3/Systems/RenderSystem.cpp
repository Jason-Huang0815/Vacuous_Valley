#include "RenderSystem.h"

#include "../Core/GameState.h"

RenderSystem::RenderSystem(GameState &state) : m_state(state) {
}

void RenderSystem::render() const {
    m_state.camera.target = {.x = m_state.player.positionX, .y = m_state.player.positionY};

    _drawPerson();
    _drawFence();
    _drawHouse();
}

void RenderSystem::_drawPerson() const {
    DrawRectangle(m_state.player.positionX - m_state.player.width / 2,
                  m_state.player.positionY - m_state.player.height / 2,
                  m_state.player.width, m_state.player.height,DARKGRAY);
}

void RenderSystem::_drawFence() const {
    for (const auto &fence: m_state.fences) {
        DrawCircle(fence.positionX, fence.positionY, fence.radius, fence.color);
    }
}

void RenderSystem::_drawHouse() const {
    for (const auto &house: m_state.houses) {
        DrawRectangle(house.building.positionX, house.building.positionY, house.building.size, house.building.size,
                      house.building.color);

        DrawRectangle(house.window.positionX, house.window.positionY, house.window.size, house.window.size,
                      house.window.color);
        DrawRectangleLines(house.window.positionX, house.window.positionY, house.window.size, house.window.size,
                           BLACK);
        DrawLine(house.window.positionX, house.window.positionY + house.window.size / 2,
                 house.window.positionX + house.window.size, house.window.positionY + house.window.size / 2,BLACK);
        DrawLine(house.window.positionX + house.window.size / 2, house.window.positionY,
                 house.window.positionX + house.window.size / 2, house.window.positionY + house.window.size,BLACK);

        DrawRectangle(house.door.positionX, house.door.positionY, house.door.width, house.door.height,
                      house.door.color);
        DrawRectangleLines(house.door.positionX, house.door.positionY, house.door.width, house.door.height,BLACK);

        const float handleRadius = house.door.width / 10;
        DrawCircle(house.door.positionX + handleRadius, house.door.positionY + house.door.height / 2, handleRadius,
                        BROWN);
    }
}
