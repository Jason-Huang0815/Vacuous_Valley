/**
 * @file GameState.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief all the data: position, entity list, etc.
 */

#ifndef VACUOUSVALLEY_GAMESTATE_H
#define VACUOUSVALLEY_GAMESTATE_H
#include <vector>

enum class Scene {
    VILLAGE, HOUSE, NOTE
};

enum class State {
    LOOKING_FOR, FOUND_KEY, ENTRE_HOUSE
};

class GameState {
public:
    Scene scene = Scene::VILLAGE;
    State state = State::LOOKING_FOR;
    Camera2D camera;

    struct Screen {
        float width = GetScreenWidth();
        float height = GetScreenHeight();
    } screen;

    struct World {
        float width = GetScreenWidth() * 2;
        float height = GetScreenHeight() * 2;
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
    } fence;

    std::vector<Fence> fences;

    void initCamera() {
        camera.target = {.x = player.positionX, .y = player.positionY};
        camera.offset = {.x = screen.width / 2.0f, .y = screen.height / 2.0f};
        camera.rotation = 0;
        camera.zoom = 1;
    }

    void initFence() {
        Fence f;
        const float halfX = world.width / 2.0f;
        const float halfY = world.height / 2.0f;
        for (float x = -halfX; x <= halfX; x += f.radius * 2) {
            f.positionX = x;
            f.positionY = halfY;
            fences.push_back(f);
            f.positionY = -halfY;
            fences.push_back(f);
        }
        for (float y = -halfY; y <= halfY; y += f.radius * 2) {
            f.positionX = halfX;
            f.positionY = y;
            fences.push_back(f);
            f.positionX = -halfX;
            fences.push_back(f);
        }
    }
};


#endif //VACUOUSVALLEY_GAMESTATE_H
