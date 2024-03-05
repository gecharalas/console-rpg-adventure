#include <iostream>
#include "Spirit.h"

Spirit::Spirit(unsigned int level)
//Monster(    name    , level, health, min_damage,max_damage,defense, dodgeChance)
:Monster("Spirit", level, level*40, level*8, level*13, level*1 + 10, level*2 + 20)
{
    std::cout << "A spirit is trying to block your way!" << std::endl;
    std::cout << "You must fight it to move on!" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}

void Spirit::showStats(){
    std::cout << std::endl;
    std::cout << "Spirit stats: " << std::endl << std::endl;
    Monster::showStats();
}
