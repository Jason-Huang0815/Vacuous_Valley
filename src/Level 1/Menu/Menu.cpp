//
// Created by 反六王联盟盟主 on 2026/8/10.
//

#include "Menu.h"
#include"raylib.h"
#include"../Core/Core.h"
#include"../../Level 2/Core2/Core2.h"
#define WIDTH (float)GetScreenWidth()
#define HEIGHT (float)GetScreenHeight()

Menu::Menu() : choice(0), alpha(255.0f), ExitRequest(false) {
}

void Menu::Choose(bool &enter, bool &exit) {
    if (IsKeyPressed(KEY_S))
        choice = 1;
    if (IsKeyPressed(KEY_W))
        choice = 0;
    if (IsKeyPressed(KEY_ENTER)) {
        if (choice == 0)
            enter = true;
        else {
            exit = true;
            ExitRequest = true;
        }
    }
}

void Menu::Draw() const {
    constexpr auto choice1 = "Enter the game";
    constexpr auto choice2 = "Leave the game";
    constexpr auto choice3 = "respawn";
    constexpr auto tip = "W/S to choose. Enter to confirm.";
    constexpr int choice_size = 50;
    constexpr int tip_size = 30;
    const float choice1_w = MeasureText(choice1, choice_size);
    const float choice2_w = MeasureText(choice2, choice_size);
    const float tip_w = MeasureText(tip, tip_size);
    if (!Core::revive||Core2::victory)
        DrawText(choice1, (WIDTH - choice1_w) / 2,HEIGHT * 2 / 3, choice_size,RED);
    else
        DrawText(choice3, (WIDTH - choice1_w) / 2,HEIGHT * 2 / 3, choice_size,RED);
    DrawText(choice2, (WIDTH - choice2_w) / 2,HEIGHT * 2 / 3 + 50, choice_size,RED);
    DrawText(tip, (WIDTH - tip_w) / 2,HEIGHT * 4 / 5, tip_size,RED);
    constexpr auto text = "VACUOUS VALLEY";
    constexpr int fontsize = 180;
    const int text_width = MeasureText(text, fontsize);
    constexpr int text_height = fontsize;
    DrawText(text, (WIDTH - text_width) / 2, (HEIGHT - text_height) / 2 - 150, fontsize,
             (Color){.r = 255, .g = 0, .b = 0, .a = (unsigned char) alpha});

    const Vector2 ball1_position = {.x = (WIDTH - choice1_w) / 2 - 50, .y = (float) (HEIGHT * 2 / 3 + 20)};
    const Vector2 ball2_position = {.x = (WIDTH - choice2_w) / 2 - 50, .y = (float) (HEIGHT * 2 / 3 + 70)};
    if (choice == 0)
        DrawCircleV(ball1_position, 10,WHITE);
    else
        DrawCircleV(ball2_position, 10,WHITE);
}

bool Menu::ShouldExit() const {
    return ExitRequest;
}
