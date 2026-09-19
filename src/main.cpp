#include"raylib.h"
#include "Level 1/Core/Core.h"
#include "Level 2/Core2/Core2.h"
#include "Level 3/Level_3.h"
#define WIDTH (float)GetScreenWidth()
#define HEIGHT (float)GetScreenHeight()

/*
 * TODO:
 * exit
 * wall
 */

/*
 * PARAMS:
 * world:20*20*screen
 * character:40*40
 * trees:3000
 * monsterds:200+180
 */

int main() {
    InitWindow(WIDTH,HEIGHT, "Vacuous Valley");
    SetTargetFPS(60);
    while (true) {
        Core level1;
        if (!level1.Run())
            break;
        if (Core2 level2(level1.GetPlayerPosition()); !level2.Run()) {
            continue;
        }
        level1.Reset();
        break;
    }
    const Level_3 level3;
    level3.run();
    CloseWindow();
    return 0;
}
