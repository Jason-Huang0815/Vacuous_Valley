//
// Created by 反六王联盟盟主 on 2026/8/11.
//

#include<raylib.h>
#include<math.h>
#include<time.h>
#include<iostream>
#include "Monster.h"
#define WIDTH (float)GetScreenWidth()
#define HEIGHT (float)GetScreenHeight()

Monster::Monster(const double speed, const int walk_r, const int detect_radius,
                 const int endurance, const Vector2 centre, const Color color) : walk_r(walk_r),
    detect_radius(detect_radius),
    endurance(endurance), centre(centre),
    color(color), angle(static_cast<float>(rand() % 360) * DEG2RAD), speed(speed), physique(0) {
    position.x = centre.x + walk_r;
    position.y = centre.y;
}

void Monster::Random_Walk() {
    if (chasing)
        return;
    angle += speed * GetFrameTime();
    position.x = centre.x + walk_r * cos(angle);
    position.y = centre.y + walk_r * sin(angle);
}

bool Monster::Detect(const Vector2 &Player_position) {
    int distance = pow(Player_position.x - position.x, 2) + pow(Player_position.y - position.y, 2);
    if (distance <= detect_radius * detect_radius || chasing) {
        return Chase(Player_position);
    }
    return false;
}

bool Monster::Chase(const Vector2 &Player_position) {
    if (!chasing) {
        chasing = true;
        physique = 0.0f;
    }
    if (Player_position.x < position.x) position.x -= speed * 1.5 * GetFrameTime() * 70;
    if (Player_position.x > position.x) position.x += speed * 1.5 * GetFrameTime() * 70;
    if (Player_position.y < position.y) position.y -= speed * 1.5 * GetFrameTime() * 70;
    if (Player_position.y > position.y) position.y += speed * 1.5 * GetFrameTime() * 70;
    physique += GetFrameTime();
    if (physique >= endurance || CheckCollisionCircleRec(position, 30,
                                                         {Player_position.x - 20, Player_position.y - 20, 40, 40})) {
        chasing = false;
        if (physique >= endurance) {
            Random_Walk();
            return false;
        }
        Kill();
        return true;
    }
    return false;
}

bool Monster::Kill() {
    //这里有真实网图跳杀，先pass
    return true;
}

std::vector<Monster> Monster::CreateSlow(const int num) {
    std::vector<Monster> slow;
    srand(time(nullptr));
    for (int i = 1; i <= num; i++) {
        Vector2 centre;
        centre.x = rand() % (static_cast<int>(WIDTH) * 20) - static_cast<int>(WIDTH) * 10;
        centre.y = rand() % (static_cast<int>(HEIGHT) * 20) - static_cast<int>(HEIGHT) * 10;
        centre = {.x = centre.x, .y = centre.y};
        Monster newone(4, 160, 700, 20, centre,BLUE);
        slow.push_back(newone);
    }
    return slow;
}

std::vector<Monster> Monster::CreateFast(const int num) {
    std::vector<Monster> fast;
    for (int i = 1; i <= num; i++) {
        Vector2 centre;
        centre.x = rand() % (static_cast<int>(WIDTH) * 20) - static_cast<int>(WIDTH) * 10;
        centre.y = rand() % (static_cast<int>(HEIGHT) * 20) - static_cast<int>(HEIGHT) * 10;
        centre = {.x = centre.x, .y = centre.y};
        Monster newone(5.5, 60, 500, 5, centre,RED);
        fast.push_back(newone);
    }
    return fast;
}

void Monster::Draw() const {
    DrawCircleV(position, 30, color);
}
