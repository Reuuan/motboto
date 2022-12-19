#pragma once
int getrand();
class character {
public:
    int hp, base_dmg, def;
    virtual int att() = 0;
    virtual int get_dmg(int a) = 0;
    character(int hpo = getrand() % 30 + 80);

};
class enemy :public character {

public:
    int condition;
    int color;
    void set_color();
    int att() override;

    int get_dmg(int a) override;
    void show_hp();
    enemy(int a);
    enemy();
    void  draw();

};
class player :public character {

public:
    int att() override;
    int get_dmg(int a) override;
    int sp, mg_dmg;
    int mg();
    player();

};
class menu {
public:
    int R;
    int call();
    int call(int a);
};