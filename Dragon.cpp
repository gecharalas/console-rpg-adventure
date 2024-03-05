#include <iostream>
#include "Dragon.h"

Dragon::Dragon(unsigned int level)
//Monster(    name    , level, health, min_damage,max_damage,defense, dodgeChance)
:Monster("Dragon", level, level*40, level*11, level*17, level*1 + 10, level*1 + 10)
{
    std::cout << "Oh no! You just encountered a fire spitting dragon!" << std::endl;
    std::cout << "You must fight him to move on!" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}

void Dragon::showStats(){
    std::cout << std::endl;
    std::cout << "Dragon stats: " << std::endl << std::endl;
    Monster::showStats();
}
