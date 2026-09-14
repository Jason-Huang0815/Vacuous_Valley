/**
 * @file GameState.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief all the data: position, entity list, etc.
 */

#ifndef VACUOUSVALLEY_GAMESTATE_H
#define VACUOUSVALLEY_GAMESTATE_H

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

    struct {
        const float width = GetScreenWidth() * 20;
        const float height = GetScreenHeight() * 20;
    } world;

    struct {
        float positionX;
        float positionY;
        const int width = 40;
        const int height = 40;
    } player;
};


#endif //VACUOUSVALLEY_GAMESTATE_H
