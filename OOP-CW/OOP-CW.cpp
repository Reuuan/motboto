#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cstdlib> 
int getrand()
{
    int r;
    srand(time(NULL));
    r = rand();
    return r;
}

class character {
public:
    int hp, base_dmg, def;
    virtual int att() = 0;
    virtual int get_dmg(int a) =0 ;
    character(int hpo= getrand() % 100 + 10);

};
class enemy:public character {

public:
    int condition;
    int color;
    void set_color();
    int att() override;
    int att(int df);
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

int main()
{
    int R, d, m, men;
    enemy en1;
    enemy en2(2);
    player pl;
    menu mn;
    
    bool check = 0;
    men = mn.call(1);
    int a = 1;

    switch (men) {
    case 1:
        while (check != 1) {
          
            R = mn.call();
            switch (R)
            {

            case 1:
                d = pl.att();
                check = en1.get_dmg(d);
                std::cout << std::endl << "Fighter  hp: " << en1.hp << std::endl;
                std::cout << std::endl << "You dealed " << d << "damage" << std::endl;
                //en1.statement = ((en1.hp * 10) / hpe1) / 2;

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
            std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            Sleep(3000);

            d = en1.att();
            std::cout << std::endl << "Yor  hp: " << pl.hp << std::endl;
            std::cout << std::endl << "You dealt " << d << " damage" << std::endl;
            check = pl.get_dmg(d);
            if (check == 1) {
                std::cout << std::endl << "You lose!" << std::endl;
                break;
            }
            system("color 02");
            std::cout << std::endl << "=================================================" << std::endl;
            Sleep(3000);



        }
        break;
    case 2:
        en1.show_hp();
        en2.show_hp();
        while (check != 1) {


            system("color 02");
            d = en1.att();
            std::cout << std::endl << "Fighter 2 get " << d << " damage" << std::endl;
            check = en2.get_dmg(d);
            en2.draw();
            

            if (check == 1) {
                std::cout << std::endl << "Fighter 2 loose!" << std::endl;
                break;
            }
            Sleep(5000);
            std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            system("color 03");
            
            d = en2.att();
            std::cout << std::endl << "Fighter 1 get " << d << "damage" << std::endl;
            check = en1.get_dmg(d);
            en1.draw();
            
            if (check == 1) {
                std::cout << std::endl << "Figther 1 loose!" << std::endl;
                break;
            }

            Sleep(5000);
            std::cout << std::endl << "=================================================" << std::endl;
            
        }
        break;
    case 3:
        break;
    }
}
//список инициализации 
character::character(int hpo):hp(hpo) {
    
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
    std::cout << std::endl << "Fighter "<< color<< " hp: "<< hp << std::endl;
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
