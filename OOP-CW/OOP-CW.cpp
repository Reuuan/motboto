#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cstdlib> 
#include "class.h"




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

