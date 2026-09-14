//
// Created by 反六王联盟盟主 on 2026/8/21.
//

#include "Exit.h"

Exit::Exit()=default;

void Exit::DrawExit(const Vector2 position) {
    //length: 400   height: 300
    square={position.x-200,position.y-250,400,250};
    DrawRectangle(square.x,square.y,square.width,square.height,GREEN);
    DrawText("EXIT",position.x-190,position.y-200,150,WHITE);
}

bool Exit::ReachExit(const Vector2 &player_pos) const {
    const Rectangle player={player_pos.x-20,player_pos.y-20,40,40};
    return CheckCollisionRecs(player,square);
}
