#include <iostream>
#include <cstdlib>
#include "Monster.h"

Monster::Monster(std::string name, unsigned int level, int healthPower, unsigned int min_damage,
                 unsigned int max_damage, unsigned int defense, unsigned int dodgeChance)
:Living(name, level, healthPower),min_damage(min_damage), max_damage(max_damage),
defense(defense), dodgeChance(dodgeChance)
{

}

void Monster::showStats(){

    std::cout << "Health: " << healthPower << "/" << maxHealth << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Damage: " << min_damage << "-" << max_damage << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Dodge Chance: " << dodgeChance << "%" << std::endl;
    std::cout << std::endl << std::endl;

}


unsigned int Monster::getDamage(){

    unsigned int a = rand() % (max_damage - min_damage + 1);


    return (min_damage + a);
}


unsigned int Monster::getDodgeChance(){

    return dodgeChance;

}




unsigned int Monster::getDefense(){

    return defense;

}

