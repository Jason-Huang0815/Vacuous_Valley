//
// Created by 反六王联盟盟主 on 2026/8/10.
//

#ifndef RUBBISH_LEVEL1_H
#define RUBBISH_LEVEL1_H
#include<vector>
#include"raylib.h"
#include"../Menu/Menu.h"
#include"../Tree/Tree.h"
#include"../River/River.h"


class Core {
protected:
    Vector2 Player_position;
    int night_countdown;
    bool running, in_menu, in_game, should_quit;
    Menu menu;
    Camera2D camera;
    static std::vector<Tree> trees;
    static River river;
    static bool world;
    mutable bool river_found;
    Sound step;

public:
    static bool revive;

    Core();

    explicit Core(Vector2 pos);

    virtual ~Core() = default;

    virtual bool Run();

    void UpdateMenu();

    virtual void DrawDone();

    virtual void UpdateGame();

    virtual void DrawTarget();

    virtual void DrawGame();

    void Move();

    void Night() const;

    bool Success() const;

    Vector2 GetPlayerPosition() const;

    static void Reset();
};


#endif //RUBBISH_LEVEL1_H
