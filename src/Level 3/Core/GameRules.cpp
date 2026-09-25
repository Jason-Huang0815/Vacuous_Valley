#include "GameRules.h"
#include "GameState.h"
#include "raylib.h"

void GameRules::update(GameState &state) {
    enterUI(state);
}

void GameRules::enterUI(GameState &state) {
    BeginMode2D(state.camera);
    bool nearDoor = false;

    const Rectangle player = {
        .x = state.player.positionX - state.player.width / 2,
        .y = state.player.positionY - state.player.height / 2,
        .width = (float) state.player.width, .height = (float) state.player.height,
    };

    for (const auto &house: state.houses) {
        const Rectangle door = {
            .x = house.door.positionX - 100, .y = house.door.positionY - 100,
            .width = (float) house.door.width + 200, .height = (float) house.door.height + 200,
        };

        if (CheckCollisionRecs(door, player)) {
            nearDoor = true;
            break;
        }
    }

    if (nearDoor && state.states.top() != State::NEAR_DOOR&&state.states.top() != State::ENTRE_HOUSE) {
        state.states.push(State::NEAR_DOOR);
    } else if (!nearDoor && state.states.top() == State::NEAR_DOOR) {
        state.states.pop();
    }

    EndMode2D();
}

void GameRules::enterRoom(GameState &state) {
    if (state.states.top() != State::ENTRE_HOUSE) {
        state.states.push(State::ENTRE_HOUSE);
    }
}

void GameRules::exitRoom(GameState &state) {
    if (state.states.top() == State::ENTRE_HOUSE) {
        state.states.pop();
    }
}
