#include <iostream>
#include <time.h>
#include<Windows.h>
#include <cstdlib> 
class character {
public:
    
  
    virtual void move() = 0;
   
    
};
class enemy  {
public:
    int hp, base_dmg, def;
    int att();
    int get_dmg(int a);
    int statement = 1;
    enemy();
private:
   
    void  draw(int a);

};
class player :public enemy {
	
public:
    int sp, mg_dmg;
    int mg();
    player();

};

int getrand()
{
    int r;
    srand(time(NULL));
    r = rand();
    return r % 19;
}


int main_menu()
{

	std::cout << std::endl  << "1.Player vs Computer " << std::endl;
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
    enemy en1, en2;
    player pl;
    hpp = pl.hp;
    hpe1 = en1.hp;
    hpe2=en2.hp;
    bool check = 0;
    menu = main_menu();

    switch (menu) {
    case 1:
        while (check != 1) {
            R = battle_menu();
            switch (R)
            {

            case 1:
                d = pl.att();
                check = en1.get_dmg(d);
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
                std::cout << std::endl << "You dealed " << m << " mage damage" << std::endl;
                if (check == 1) {
                    break;
                }
                break;
            case 3:
                pl.def += 2;

            case 5:
                if (rand() % 2) {
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
            }

            d = en1.att();
            std::cout << std::endl << "You get " << d << "damage" << std::endl;
            check = pl.get_dmg(d);
            if (check == 1) {
                std::cout << std::endl << "You lose!" << std::endl;
                break;
            }
            system("07");
            Sleep(3000);

            

        }
        break;
    case 2:
        while (check != 1) {
            
            d = en1.att();
            std::cout << std::endl << "Get " << d << "damage" << std::endl;
            check = en2.get_dmg(d);
            if (check == 1) {
                std::cout << std::endl << "You lose!" << std::endl;
                break;
            }
            Sleep(3000);
            
            d = en2.att();
            std::cout << std::endl << "Get " << d << "damage" << std::endl;
            check = en1.get_dmg(d);
            if (check == 1) {
                std::cout << std::endl << "You lose!" << std::endl;
                break;
            }
            
            Sleep(3000);
            std::cout << std::endl << "=================================================" << std::endl;

        }
        break;
    case 3:
        break;
    }
}

enemy::enemy() {
    hp = rand() % 100 + 1;
    base_dmg = rand() % 10 + 1;
    def = rand() % 5 + 1;
    
};
int enemy::att() {
    int a = base_dmg + rand() % 10;
    return a;
}
int player::mg() {
    if (sp < 10) {
        std::cout << std::endl << "You havent enough spell points!!! " << std::endl;
        return 0;
    }
    else {

        int a = mg_dmg + rand() % 10;
        sp -= 10;
        return a;
    }
}

int enemy::get_dmg(int dm) {
    hp -= dm-def;
    int a = rand() % 5 + 1;
    if (hp > 0) {
        if (a== 5) {
            draw(a);
            return 1;
        }
        else {
            draw(a);
            return 0;
        }
        
    }
    else {
        return 1;
    }
    
}
player::player() { 
    hp = rand() % 100 + 1;
    base_dmg = rand() % 10 + 1;
    def = rand() % 5 + 1;
    mg_dmg = rand() % 20 + 1;
    sp = 100;

}
void enemy::draw(int a) {
    
    printf(" o |\n/|\\|\n ^    \n/ \\   " " \n");
    switch (a)
    {

    case 1:
        
        printf(" o |\n/|\\|\n ^    \n/ \\   " " \n");
        
        break;
    case 2:
        printf(" o |\n |\\|\n ^    \n/ \\   " " \n");
        printf("Lose hand");
        
        break;
    case 3:
        printf(" o |\n |\\|\n ^    \n/ \\   " " \n");
        
        break;
    case 4:
        printf(" o |\n |\\|\n ^    \n/ \\   " " \n");
        
        break;
    case 5:
        printf("   |\n |\\|\n ^    \n/ \\   " " \n");
        printf("Lose head/n");
        
        break;
    }
    
}

