#include <iostream>
#include "Warrior.h"

Warrior::Warrior(std::string name)
:Hero(name, 16, 10, 10)
{
    std::cout << name << " the Warrior was born!" << std::endl;
}

Warrior::~Warrior()
{
    std::cout << "   The life of " << name << " came to an end!" <<  std::endl << std::endl;
}
void Warrior::levelUp(){

    unsigned int counter = this->getLevel();    //stores the current level,

    Hero::levelUp();

    while(this->getLevel() > counter){  //if true then the hero leveled up when Hero::levelUp() was called
        counter++;
        increaseStrength(8);    // +8 strength per level
        increaseDexterity(1);   // +1 dexterity per level
        if(this->getLevel() % 2 == 0)
            increaseAgility(1);     //+1 agility every 2nd level
    }
}
