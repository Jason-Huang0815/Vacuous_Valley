//
// Created by 反六王联盟盟主 on 2026/8/9.
//

#include<math.h>
#include<vector>
#include<time.h>
#include "Tree.h"

Tree::Tree(const Vector2 position, const float size, const float rotation, const Color skin) : position(position),
    size(size), rotation(rotation), skin(skin) {
}

void Tree::DrawBranch(const Vector2 pos, const float angle, const float length, const float thickness, const int depth,
                      const Color tint) {
    if (depth == 0 || length < 2.0f)
        return;
    const Vector2 end = {.x = pos.x + sin(angle) * length, .y = pos.y - cos(angle) * length};
    DrawLineEx(pos, end, thickness, tint);
    const float offset = 0.1f * (float) depth;
    DrawBranch(end, angle - offset, length * 0.65f, thickness * 0.7f, depth - 1, tint);
    DrawBranch(end, angle + offset, length * 0.65f, thickness * 0.7f, depth - 1, tint);
    if (depth > 2 && rand() % 3 == 0)
        DrawBranch(end, angle + offset * 1.5f, length * 0.5f, thickness * 0.5f, depth - 2, tint);
}

void Tree::Draw() const {
    DrawBranch(position, 0, 100.0f * size, 10.0f * size, 3, skin);
}

std::vector<Tree> Tree::Generate(int count, float width, float height) {
    std::vector<Tree> result;
    srand(time(nullptr));
    for (int i = 0; i < count; i++)
        result.push_back({
            {
                .x = (float) (rand() % (int) width - (int) (width / 2)),
                .y = (float) (rand() % (int) height - (int) (height / 2))
            },
            0.8f + (rand() % 70) / 100.0f,
            (float) (rand() % 360),
            {
                (unsigned char) (40 + rand() % 30),
                (unsigned char) (30 + rand() % 20),
                (unsigned char) (20 + rand() % 15), 255
            }
        });
    return result;
}

bool Tree::Collide(const Vector2 &Player_Position, const float Player_Size) const {
    const float half=5.0f*size;
    const Rectangle judge={position.x - half, position.y - half,half*2,half*2};
    const Rectangle player={Player_Position.x - Player_Size, Player_Position.y - Player_Size,Player_Size*2,Player_Size*2};
    return CheckCollisionRecs(judge, player);
}
