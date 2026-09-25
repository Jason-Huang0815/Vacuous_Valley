#include "RenderSystem.h"

#include "../Core/GameState.h"
#include "../Core/GameRules.h"

RenderSystem::RenderSystem(GameState &state) : m_state(state) {
}

void RenderSystem::render() const {
    m_state.camera.target = {.x = m_state.player.positionX, .y = m_state.player.positionY};

    BeginMode2D(m_state.camera);
    _drawBlood();
    _drawPerson();
    _drawFence();
    _drawHouse();
    EndMode2D();

    if (m_state.states.top() == State::ENTRE_HOUSE) {
        _drawRoom();
        _drawHousePerson();
    }

    _drawHint();
    _drawLock();
}

void RenderSystem::_drawBlood() const {
    for (const auto &blood: m_state.bloodDrops) {
        DrawEllipse(blood.position.x, blood.position.y, blood.radiusX, blood.radiusY, blood.color);
    }
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

void RenderSystem::_drawHint() const {
    std::string hint;

    switch (m_state.states.top()) {
        case State::OUTSIDE:
            hint = "Find the injector";
            break;

        case State::NEAR_DOOR:
            hint = "Press E to open the door";
            break;

        case State::ENTRE_HOUSE:
            hint = "Something here?\nOr press R to exit";
            break;

        case State::FOUND_NOTE:
            hint = "Press N to get the note";
            break;

        case State::FOUND_KEY:
            hint = "Find the chief's house";
            break;

        default:
            break;
    }

    DrawText(hint.c_str(), 20, 20, 100,GREEN);
}

void RenderSystem::_drawLock() const {
    const Rectangle player = {
        .x = m_state.player.positionX - m_state.player.width / 2,
        .y = m_state.player.positionY - m_state.player.height / 2,
        .width = (float) m_state.player.width, .height = (float) m_state.player.height,
    };

    for (const auto &house: m_state.houses) {
        const Rectangle door = {
            .x = house.door.positionX - 100, .y = house.door.positionY - 100,
            .width = (float) house.door.width + 200, .height = (float) house.door.height + 200,
        };

        if (CheckCollisionRecs(door, player) && IsKeyDown(KEY_E)) {
            if (!house.lock.canOpen) {
                const std::string message = "locked";
                DrawText(message.c_str(), house.lock.UIPosition.x, house.lock.UIPosition.y, 80,GREEN);
            } else {
                GameRules::enterRoom(m_state);
            }
            break;
        }
    }
}

void RenderSystem::_drawRoom() const {
    DrawRectangle(0,0,m_state.screen.width,m_state.screen.height,BLACK);
    DrawText("FUCK U",300,m_state.screen.height/2,800,GREEN);
}

void RenderSystem::_drawHousePerson() const {

}
