//
// Created by 反六王联盟盟主 on 2026/8/12.
//

#ifndef RUBBISH_CORE2_H
#define RUBBISH_CORE2_H
#include"../Monster/Monster.h"
#include"../../Level 1/Core/Core.h"


class Core2 : public Core {
private:
    bool death;
    bool killed;
    std::vector<Monster> slow;
    std::vector<Monster> fast;

public:
    static bool victory;

    Core2();

    explicit Core2(Vector2 pos);

    ~Core2() override;

    bool Run() override;

    void DrawTarget() override;

    void DrawGame() override;

    void UpdateGame() override;

    void DrawDone() override;

    static int DrawSuccess();

    static void DrawSuccess2();
};


#endif //RUBBISH_CORE2_H
