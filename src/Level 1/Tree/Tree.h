//
// Created by 反六王联盟盟主 on 2026/8/9.
//

#ifndef RUBBISH_TREE_H
#define RUBBISH_TREE_H
#include <vector>
#include "raylib.h"


class Tree {
private:
    Vector2 position;
    float size;
    float rotation;
    Color skin;

public:
    Tree(Vector2 position, float size, float rotation, Color skin);

    static void DrawBranch(Vector2 pos, float angle, float length, float thickness, int depth, Color tint);

    void Draw() const;

    static std::vector<Tree> Generate(int count, float width, float height);

    bool Collide(const Vector2 &Player_Position, float Player_Size) const;
};


#endif //RUBBISH_TREE_H
