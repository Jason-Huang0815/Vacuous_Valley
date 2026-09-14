//
// Created by 反六王联盟盟主 on 2026/8/21.
//

#ifndef RUBBISH_EXIT_H
#define RUBBISH_EXIT_H
#include "raylib.h"


class Exit {
private:
    Rectangle square;
public:
    Exit();

    void DrawExit(Vector2 position);

    bool ReachExit(const Vector2 &player_pos) const;
};


#endif //RUBBISH_EXIT_H
