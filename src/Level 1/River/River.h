//
// Created by 反六王联盟盟主 on 2026/8/10.
//

#ifndef RUBBISH_RIVER_H
#define RUBBISH_RIVER_H
#include"raylib.h"
#include<vector>


class River {
private:
    Vector2 turnings[4];
    std::vector<Vector2> points;

public:
    static Vector2 exit_position;

    River();

    void Draw() const;

    void Generate();

    static Vector2 SamplePoints(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, float t);

    bool IsPlayerNear(Vector2 playerPos, float radius) const;

    bool RiverKill(Vector2 playerPos) const;
};


#endif //RUBBISH_RIVER_H
