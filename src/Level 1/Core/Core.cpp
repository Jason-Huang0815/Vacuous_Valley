//
// Created by 反六王联盟盟主 on 2026/8/10.
//

#include<iostream>
#include "Core.h"
#include"raylib.h"
#include"../Tree/Tree.h"
#include"../River/River.h"
#define WIDTH (float)GetScreenWidth()
#define HEIGHT (float)GetScreenHeight()

std::vector<Tree> Core::trees;
River Core::river;
bool Core::world = false;
bool Core::revive = false;

Core::Core() : Core({WIDTH / 2,HEIGHT / 2}) {
}

Core::Core(const Vector2 pos) : Player_position(pos), night_countdown(200), running(true),
                                in_menu(true), in_game(false), should_quit(false), river_found(false), step() {
    camera.offset = (Vector2){.x = WIDTH / 2, .y = HEIGHT / 2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    if (!world) {
        trees = Tree::Generate(3000,WIDTH * 20,HEIGHT * 20);
        river.Generate();
        world = true;
    }
}

bool Core::Run() {
    InitAudioDevice();
    step=LoadSound("C:/Users/29651/Desktop/Vacuous Valley/src/Level 1/Core/steps2.mp3");
    while (running && !WindowShouldClose()) {
        BeginDrawing();
        if (in_menu)
            UpdateMenu();
        if (in_game)
            UpdateGame();
        EndDrawing();
    }
    UnloadSound(step);
    CloseAudioDevice();
    return river_found;
}

void Core::UpdateMenu() {
    ClearBackground(BLACK);
    bool enter = false;
    menu.Choose(enter, should_quit);
    if (should_quit)
        running = false;
    else if (enter) {
        in_menu = false;
        in_game = true;
    }
    menu.Draw();
}


void Core::UpdateGame() {
    ClearBackground(DARKGRAY);
    Move();
    BeginMode2D(camera);
    DrawGame();
    EndMode2D();
    DrawTarget();
    if (night_countdown <= 0)
        Night();
    else
        night_countdown--;
    DrawDone();
}

void Core::DrawDone() {
    if (Success()) {
        running = false;
    }
}

void Core::DrawTarget() {
    constexpr auto target = "Target: find the red river";
    const int textWidth = MeasureText(target, 100);
    DrawText(target, (textWidth) / 2, 80, 100, YELLOW);
}

void Core::DrawGame() {
    river.Draw();
    for (const auto &tree: trees)
        tree.Draw();
    camera.target = Player_position;
    DrawRectangle(Player_position.x - 20, Player_position.y - 20, 40, 40,WHITE);
}

void Core::Move() {
    const Vector2 oldPos = Player_position;
    static float stepTimer = 0.0f;
    bool isMoving = false;
    if (IsKeyDown(KEY_D)) { Player_position.x += 10; isMoving = true; }
    if (IsKeyDown(KEY_A)) { Player_position.x -= 10; isMoving = true; }
    if (IsKeyDown(KEY_S)) { Player_position.y += 10; isMoving = true; }
    if (IsKeyDown(KEY_W)) { Player_position.y -= 10; isMoving = true; }
    if (isMoving) {
        stepTimer += GetFrameTime();
        if (stepTimer >= 0.4f) {
            PlaySound(step);
            stepTimer = 0.0f;
        }
    } else {
        stepTimer = 0.0f;
    }
    if (Player_position.x == oldPos.x && Player_position.y == oldPos.y)
        return;
    constexpr float playerHalf = 20.0f;
    bool blockedX = false;
    for (const auto& tree : trees) {
        if (tree.Collide(Player_position, playerHalf)) {
            blockedX = true;
            break;
        }
    }
    if (blockedX) {
        Player_position.x = oldPos.x;
    }
    bool blockedY = false;
    for (const auto& tree : trees) {
        if (tree.Collide(Player_position, playerHalf)) {
            blockedY = true;
            break;
        }
    }
    if (blockedY) {
        Player_position.y = oldPos.y;
    }
}

void Core::Night() const {
    const auto [x, y] = GetWorldToScreen2D(Player_position, camera);
    DrawRectangle(0, 0,WIDTH,HEIGHT, (Color){.r = 0, .g = 0, .b = 0, .a = 200});
    BeginBlendMode(BLEND_SUBTRACT_COLORS);
    DrawCircle(x, y, 500, (Color){.r = 80, .g = 80, .b = 80, .a = 120});
    EndBlendMode();
}

bool Core::Success() const {
    if (revive) {
        river_found = true;
        return true;
    }
    if (river_found)
        return true;
    if (river.IsPlayerNear(Player_position, 600)) {
        river_found = true;
        return true;
    }
    return false;
}

Vector2 Core::GetPlayerPosition() const {
    return Player_position;
}

void Core::Reset() {
    world=false;
    revive=false;
}