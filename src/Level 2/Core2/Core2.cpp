//
// Created by 反六王联盟盟主 on 2026/8/12.
//

#include "Core2.h"

#include"raylib.h"
#include"../Monster/Monster.h"
#include"../../Level 1/Core/Core.h"
#include"../../Level 1/River/River.h"
#include"../Exit/Exit.h"
#include<vector>
#define WIDTH (float)GetScreenWidth()
#define HEIGHT (float)GetScreenHeight()

static auto ee = Exit();
static double alpha, beta;
bool Core2::victory = false;

Core2::Core2() : death(false), killed(false) {
    slow = Monster::CreateSlow(200);
    fast = Monster::CreateFast(180);
    ee = Exit();
}

Core2::Core2(const Vector2 pos) : Core(pos), death(false), killed(false) {
    slow = Monster::CreateSlow(200);
    fast = Monster::CreateFast(180);
    ee = Exit();
    alpha = beta = 0.0;
    victory = false;
}

Core2::~Core2() = default;

bool Core2::Run() {
    in_menu = false;
    in_game = true;
    night_countdown = 0;
    Core::Run();
    return !death;
}

void Core2::UpdateGame() {
    if (victory) {
        DrawSuccess();
        if (alpha >= 1.0)
            DrawSuccess2();
        if (beta >= 1.0) {
            running = false;
        }
        return;
    }
    Core::UpdateGame();
    for (auto &m: slow) {
        m.Random_Walk();
        if (m.Detect(Player_position))
            killed = true;
    }
    for (auto &m: fast) {
        m.Random_Walk();
        if (m.Detect(Player_position))
            killed = true;
    }
}

void Core2::DrawTarget() {
    constexpr auto target = "Target: Go up along the river";
    const int textWidth = MeasureText(target, 100);
    DrawText(target, (textWidth) / 2, 80, 100, YELLOW);
}

void Core2::DrawGame() {
    Core::DrawGame();
    ee.DrawExit(river.exit_position);
    for (auto m: slow)
        m.Draw();
    for (auto m: fast)
        m.Draw();
    if (death) {
        revive = true;
        running = false;
    }
    if (ee.ReachExit(Player_position)) {
        alpha = 0.0;
        victory = true;
    }
}

void Core2::DrawDone() {
    if (river.RiverKill(Player_position)) {
        constexpr auto msg = "Drawn";
        const int textWidth = MeasureText(msg, 150);
        DrawText(msg, (WIDTH - textWidth) / 2,HEIGHT / 2, 150, RED);
        WaitTime(1.5);
        death = true;
    }
    if (killed) {
        constexpr auto msg = "DIE";
        const int textWidth = MeasureText(msg, 150);
        DrawText(msg, (WIDTH - textWidth) / 2,HEIGHT / 2, 150, RED);
        WaitTime(1.5);
        death = true;
    }
}

int Core2::DrawSuccess() {
    ClearBackground(BLACK);
    constexpr auto success = "Exit";
    const int textWidth = MeasureText(success, 170);
    alpha += GetFrameTime();
    if (alpha > 1.0)
        alpha = 1.0;
    DrawText(success, (WIDTH - textWidth) / 2,HEIGHT / 2, 170, Fade(RED, alpha));
    return textWidth;
}

void Core2::DrawSuccess2() {
    const int textWidth = DrawSuccess();
    beta += GetFrameTime();
    if (beta > 1.0)
        beta = 1.0;
    DrawText("?", (WIDTH - textWidth) / 2 + 800,HEIGHT / 2, 170, Fade(RED, beta));
}
