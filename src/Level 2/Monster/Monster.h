//
// Created by 反六王联盟盟主 on 2026/8/11.
//

#ifndef RUBBISH_MONSTER_H
#define RUBBISH_MONSTER_H

#include<raylib.h>
#include<vector>

class Monster {
private:
    int walk_r, detect_radius, endurance;
    Vector2 position;
    Vector2 centre;
    Color color;
    double angle, speed;
    float physique;
    bool chasing = false;

public:
    Monster(double speed, int walk_r, int detect_radius, int endurance, Vector2 centre, Color color);

    ~Monster() = default;

    void Random_Walk();

    bool Detect(const Vector2 &Player_position);

    bool Chase(const Vector2 &Player_position);

    static bool Kill();

    static std::vector<Monster> CreateSlow(int num);

    static std::vector<Monster> CreateFast(int num);

    void Draw() const;
};


#endif //RUBBISH_MONSTER_H
