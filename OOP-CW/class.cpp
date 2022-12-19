#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cstdlib> 
#include "class.h"
int getrand()
{
    int r;
    srand(time(NULL));
    r = rand();
    return r;
}


//список инициализации 
character::character(int hpo) :hp(hpo) {

    base_dmg = getrand() % 10 + 1;
    def = getrand() % 5 + 1;
}
enemy::enemy(int a) {
    condition = 1;
    color = a;

};
enemy::enemy() {
    condition = 1;
    color = 1;

};
void enemy::show_hp() {
    std::cout << std::endl << "Fighter " << color << " hp: " << hp << std::endl;
}
int enemy::att() {
    set_color();
    int a = base_dmg + getrand() % 10 + 1;

    return a;
}
int player::att() {
    system("color 07");
    int a = base_dmg + getrand() % 10 + 1;

    return a;
}
int player::mg() {
    if (sp < 10) {
        std::cout << std::endl << "You havent enough spell points!!! " << std::endl;
        return 0;
    }
    else {

        int a = mg_dmg + getrand() % 10;
        sp -= 10;
        return a;
    }
}

int enemy::get_dmg(int dm) {
    hp -= dm - def;
    show_hp();
    if (hp > 0) {
        return 0;

    }
    else {
        return 1;
    }
}
int player::get_dmg(int dm) {
    hp -= dm - def;

    if (hp > 0) {
        return 0;

    }
    else {
        return 1;
    }

}
player::player() {

    mg_dmg = getrand() % 20 + 1;
    sp = 100;

}
void enemy::draw() {

    if (hp <= 80) {
        condition = 2;
    }
    if (hp <= 60) {
        condition = 3;
    }
    if (hp <= 40) {
        condition = 4;
    }
    if (hp <= 20) {
        condition = 5;
    }

    switch (condition)
    {

    case 1:

        printf(" o |\n/|\\|\n ^    \n/ \\   " " \n");

        break;
    case 2:
        printf(" o |\n |\\|\n ^    \n/ \\   " " \n");
        printf("Lose hand\n");

        break;
    case 3:
        printf(" o \n |\n ^    \n/ \\   " " \n");
        printf("Lose hand\n");

        break;
    case 4:
        printf(" o \n |\n ^    \n  \\   " " \n");
        printf("Lose leg\n");
        break;
    case 5:
        printf(" o  \n |\n ^    \n      " " \n");
        printf("Lose leg\n");
        break;
    }

}

int menu::call() {
    std::cout << std::endl << "____Choose action____" << std::endl << std::endl;
    std::cout << std::endl << "1.Attack" << std::endl;
    std::cout << std::endl << "2.Magic" << std::endl;
    std::cout << std::endl << "3.Defense" << std::endl;
    std::cout << std::endl << "4.Run" << std::endl;
    std::cout << std::endl << "_____________________________________" << std::endl;

    int R;
    std::cin >> R;
    return R;
}
int menu::call(int a) {
    std::cout << std::endl << "1.Player vs Computer " << std::endl;
    std::cout << std::endl << "2.Computer vs computer" << std::endl;
    std::cout << std::endl << "3.Exit" << std::endl;

    int R;
    std::cin >> R;
    return R;
}
void enemy::set_color() {
    switch (color)
    {

    case 1:
        system("color 02");
        break;
    case 2:
        system("color 03");
        break;
    }

}
