/**
 * @file GameRules.h
 * @author 反六王联盟盟主
 * @date 2026/8/25
 * @brief Only rules controller: collision judge, success condition, etc.
 */

#ifndef VACUOUSVALLEY_GAMERULES_H
#define VACUOUSVALLEY_GAMERULES_H

class GameState;

class GameRules {
public:
    static void update(GameState& state);

    static void enterUI(GameState& state);

    static void enterRoom(GameState& state);

    static void exitRoom(GameState& state);
};


#endif //VACUOUSVALLEY_GAMERULES_H
