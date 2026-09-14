//
// Created by 反六王联盟盟主 on 2026/8/10.
//


#include "River.h"
#include <cstdlib>
#include <ctime>
#define WIDTH (float)GetScreenWidth()
#define HEIGHT (float)GetScreenHeight()

Vector2 River::exit_position={.x = 0,.y = 0};

River::River() = default;

void River::Generate() {
    srand(time(nullptr));
    turnings[0] = {static_cast<float>(-rand() % 200), -HEIGHT * 10};
    turnings[1] = {rand() % 7 * WIDTH, static_cast<float>(-rand() % 150)};
    turnings[2] = {-rand() % 7 * WIDTH, static_cast<float>(rand() % 50)};
    turnings[3] = {static_cast<float>(rand() % 200), HEIGHT * 10};
    constexpr int segments = 350;
    points.clear();
    for (int i = 0; i <= segments; ++i) {
        const float t = static_cast<float>(i) / segments;
        points.push_back(SamplePoints(turnings[0], turnings[1], turnings[2], turnings[3], t));
    }
    exit_position=points[0];
}

void River::Draw() const {
    DrawSplineBezierCubic(turnings, 4, 60,RED);
}

Vector2 River::SamplePoints(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, float t) {
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    Vector2 p;
    p.x = uu * u * p0.x + 3 * uu * t * p1.x + 3 * u * tt * p2.x + tt * t * p3.x;
    p.y = uu * u * p0.y + 3 * uu * t * p1.y + 3 * u * tt * p2.y + tt * t * p3.y;
    return p;
}

bool River::IsPlayerNear(Vector2 playerPos, float radius) const {
    float radiusSq = radius * radius;
    for (const auto &p: points) {
        float dx = playerPos.x - p.x;
        if (float dy = playerPos.y - p.y; dx * dx + dy * dy < radiusSq) {
            return true;
        }
    }
    return false;
}

bool River::RiverKill(const Vector2 playerPos) const {
    return IsPlayerNear(playerPos, 30);
}
