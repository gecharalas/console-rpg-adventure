#include <iostream>
#include "Exosceleton.h"

Exosceleton::Exosceleton(unsigned int level)
//Monster(    name    , level, health, min_damage,max_damage,defense, dodgeChance)
:Monster("Exosceleton", level, level*40, level*8, level*13, level*2 + 15, level*1 + 10)
{
    std::cout << "An Exosceleton is coming your way!" << std::endl;
    std::cout << "You must fight it to move on!" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}

void Exosceleton::showStats(){
    std::cout << std::endl;
    std::cout << "Exosceleton stats: " << std::endl << std::endl;
    Monster::showStats();
}
