/**
 * @file GameState.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief all the data: position, entity list, etc.
 */

#ifndef VACUOUSVALLEY_GAMESTATE_H
#define VACUOUSVALLEY_GAMESTATE_H
#include <iostream>
#include <vector>
#include<raylib.h>
#include <stack>

#include"../../utils/Random.h"

enum class Scene {
    VILLAGE, HOUSE, NOTE
};

enum class State {
    OUTSIDE, NEAR_DOOR, ENTRE_HOUSE, FOUND_KEY, FOUND_NOTE
};

class GameState {
public:
    Scene scene = Scene::VILLAGE;
    std::stack<State> states;
    Camera2D camera;

    struct Screen {
        float width = GetScreenWidth();
        float height = GetScreenHeight();
    } screen;

    struct World {
        float width = GetScreenWidth() * 10;
        float height = GetScreenHeight() * 10;
    } world;

    struct Player {
        float positionX = GetScreenWidth() / 2.0f;
        float positionY = GetScreenHeight() / 2.0f;
        int width = 40;
        int height = 40;
    } player;

    struct Fence {
        float positionX;
        float positionY;
        float radius = 50;
        Color color = BROWN;
    };

    struct House {
        struct buiding {
            float positionX;
            float positionY;
            int size;

            Color colors[3] = {{.r = 139, .g = 0, .b = 0, .a = 255},BROWN,GRAY};
            Color color;
        } building;

        struct Window {
            float positionX;
            float positionY;
            int size;

            Color colors[3] = {DARKBLUE,LIGHTGRAY,MAROON};
            Color color;
        } window;

        struct Door {
            float positionX;
            float positionY;
            int width = 200;
            int height;
            Color color = DARKBROWN;
        } door;

        struct Lock {
            bool canOpen;
            Vector2 UIPosition;
        } lock;
    };

    struct BloodDrop {
        Vector2 position;
        float radiusX;
        float radiusY;
        Color color;
    } bloodDrop;

    std::vector<Fence> fences;
    std::vector<House> houses;
    std::vector<BloodDrop> bloodDrops;

    void init() {
        states.push(State::OUTSIDE);
        initCamera();
        initFence();
        initHouse();
        initBlood();
    }

    void initCamera() {
        camera.target = {.x = player.positionX, .y = player.positionY};
        camera.offset = {.x = screen.width / 2.0f, .y = screen.height / 2.0f};
        camera.rotation = 0;
        camera.zoom = 1;
    }

    void initFence() {
        Fence fence;
        const float halfX = world.width / 2.0f;
        const float halfY = world.height / 2.0f;

        for (float x = -halfX; x <= halfX; x += fence.radius * 2) {
            fence.positionX = x;
            fence.positionY = halfY;
            fences.push_back(fence);
            fence.positionY = -halfY;
            fences.push_back(fence);
        }

        for (float y = -halfY; y <= halfY; y += fence.radius * 2) {
            fence.positionX = halfX;
            fence.positionY = y;
            fences.push_back(fence);
            fence.positionX = -halfX;
            fences.push_back(fence);
        }
    }

    void initHouse(const int quantity = 50) {
        houses.reserve(quantity);

        for (int i = 0; i < quantity; i++) {
            House house;

            house.building.size = random(500, 800);
            house.building.positionX = random(-world.width / 2.0f, world.width / 2.0f - house.building.size);
            house.building.positionY = random(-world.height / 2.0f, world.height / 2.0f - house.building.size);
            house.building.color = house.building.colors[random(0, 2)];

            house.window.size = house.building.size / 5;
            house.window.positionX = house.building.positionX + random(0, house.building.size - house.window.size);
            house.window.positionY = house.building.positionY;
            house.window.color = house.window.colors[random(0, 2)];

            house.door.height = random((float) house.building.size / 3,
                                       (float) house.building.size - house.window.size);
            house.door.positionX = house.building.positionX + random(0, house.building.size - house.door.width);
            house.door.positionY = house.building.positionY + house.building.size - house.door.height;
            houses.push_back(house);

            if (i < quantity / 2) {
                house.lock.canOpen = true;
            } else {
                house.lock.canOpen = false;
            }
            house.lock.UIPosition = {.x = player.positionX - 40, .y = player.positionY};
        }
    }

    void initBlood() {
        bloodDrops.clear();

        for (int i = 0; i < 1000; i++) {
            BloodDrop drop;

            drop.position = {
                .x = random((float) -0.5 * world.width, (float) 0.5 * world.width),
                .y = random((float) -0.5 * world.height, (float) 0.5 * world.height)
            };
            const float radius = random(50, 100);
            drop.radiusX = radius;
            drop.radiusY = radius * 0.5f;
            drop.color = {.r = (unsigned char) random(80, 130), .g = 0, .b = 0, .a = 150};

            bloodDrops.push_back(drop);
        }
    }
};


#endif //VACUOUSVALLEY_GAMESTATE_H
