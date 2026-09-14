//
// Created by 反六王联盟盟主 on 2026/8/10.
//

#ifndef RUBBISH_MENU_H
#define RUBBISH_MENU_H


class Menu {
private:
    int choice;
    float alpha;
    bool ExitRequest;

public:
    Menu();

    void Choose(bool &enter, bool &exit);

    void Draw() const;

    bool ShouldExit() const;
};


#endif //RUBBISH_MENU_H
