#include <iostream>
#include <time.h>
#include<Windows.h>
#include <cstdlib> 
class character {
public:
    virtual int get_dmg()=0;
    virtual in att()=0;
    virtual void draw()=0;
    virtual void move() = 0;
};
class enemy :public character {
private:
    int hp, base_dmg, def, statement=1, color;

public:
    int att(int df);
    int get_dmg(int a);
    void  draw(int a);
    enemy();
};
class player :public character {
private:
    int hp, base_dmg, def, color;
public:
    int att(df);
    int get_dmg(int a);
    int sp, mg_dmg;
    int mg();
    player();

};

int getrand()
{
    int r;
    srand(time(NULL));
    r = rand();
    return r;
}


int main_menu()
{

    std::cout << std::endl << "1.Player vs Computer " << std::endl;
    std::cout << std::endl << "2.Computer vs computer" << std::endl;

    std::cout << std::endl << "3.exit" << std::endl;

    int R;
    std::cin >> R;
    return R;
}

int battle_menu()
{
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
int main()
{
    int R, d, m, hpe1, hpe2, hpp, menu;
    enemy en1;
    enemy en2;
    player pl;
    hpp = pl.hp;
    hpe1 = en1.hp;
    hpe2 = en2.hp;
    bool check = 0;
    menu = main_menu();
    int a = 1;

    switch (menu) {
    case 1:
        while (check != 1) {
            system("color 07");
            R = battle_menu();
            switch (R)
            {

            case 1:
                d = pl.att();
                check = en1.get_dmg(d);
                std::cout << std::endl << "Fighter  hp: " << en1.hp << std::endl;
                std::cout << std::endl << "You dealed " << d << "damage" << std::endl;
                en1.statement = ((en1.hp * 10) / hpe1) / 2;

                if (check == 1) {
                    std::cout << std::endl << "You win! " << std::endl;
                    break;
                }
                break;
            case 2:

                m = pl.mg();
                check = en1.get_dmg(m);
                std::cout << std::endl << "Fighter  hp: " << en1.hp << std::endl;
                std::cout << std::endl << "You dealed " << m << " mage damage" << std::endl;
                if (check == 1) {
                    break;
                }
                break;
            case 3:
                pl.def += 2;

            case 5:
                if ((getrand() % 2) == 0) {
                    std::cout << std::endl << "You escaped!" << std::endl;
                    break;
                    check = 1;
                }
                else {
                    std::cout << std::endl << "Escape false" << std::endl;
                }
                break;

            }
            if (check == 1) {
                break;
                continue;
            }
            Sleep(5000);

            d = en1.att();
            std::cout << std::endl << "Yor  hp: " << pl.hp << std::endl;
            std::cout << std::endl << "You get " << d << " damage" << std::endl;
            check = pl.get_dmg(d);
            if (check == 1) {
                std::cout << std::endl << "You lose!" << std::endl;
                break;
            }
            system("color 02");
            Sleep(5000);



        }
        break;
    case 2:
        std::cout << std::endl << "Fighter 1 hp: " << en1.hp << std::endl;
        std::cout << std::endl << "Fighter 2 hp: " << en1.hp << std::endl;
        while (check != 1) {


            system("color 02");
            d = en1.att();
            std::cout << std::endl << "Fighter 2 get " << d << " damage" << std::endl;
            check = en2.get_dmg(d);
            en2.draw(a);

            if (check == 1) {
                std::cout << std::endl << "Fighter 2 loose!" << std::endl;
                break;
            }
            Sleep(5000);
            system("color 03");
            std::cout << std::endl << "Fighter 1 hp: " << en1.hp << std::endl;
            d = en2.att();
            std::cout << std::endl << "Fighter 1 get " << d << "damage" << std::endl;
            check = en1.get_dmg(d);
            en1.draw(a + 1);
            if (check == 1) {
                std::cout << std::endl << "Figther 1 loose!" << std::endl;
                break;
            }

            Sleep(5000);
            std::cout << std::endl << "=================================================" << std::endl;
            a++;
        }
        break;
    case 3:
        break;
    }
}

enemy::enemy() {
    hp = getrand() % 100 + 1;
    base_dmg = getrand() % 10 + 1;
    def = getrand() % 5 + 1;

};
int player::att(){
    int a=base_dmg +getrand()%10+1;
    return a;
}
int player::att(int a) {
    return 0;
}
int enemy::att() {
    int a = base_dmg + getrand() % 10 + 1;

    return a;
}
int enemy::att(int a) {
    return 0;
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
    hp = getrand() % 100 + 1;
    base_dmg = getrand() % 10 + 1;
    def = getrand() % 5 + 1;
    mg_dmg = getrand() % 20 + 1;
    sp = 100;

}
void enemy::draw(int a) {


    switch (a)
    {

    case 1:

        printf(" o |\n/|\\|\n ^    \n/ \\   " " \n");

        break;
    case 2:
        printf(" o |\n |\\|\n ^    \n/ \\   " " \n");
        printf("Lose hand/n");

        break;
    case 3:
        printf(" o \n |\n ^    \n/ \\   " " \n");
        printf("Lose hand/n");

        break;
    case 4:
        printf(" o \n |\\|\n ^    \n  \\   " " \n");
        printf("Lose leg/n");
        break;
    case 5:
        printf(" o  \n |\\|\n ^    \n      " " \n");
        printf("Lose leg/n");

        break;
    }
    if (a > 5) {
        printf(" o  \n |\\|\n ^    \n/ \\   " " \n");
    }
}

