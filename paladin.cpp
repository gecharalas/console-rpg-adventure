#include <iostream>
#include "Paladin.h"

Paladin::Paladin(std::string name)
:Hero(name, 16, 16, 7)
{
    std::cout << name << " the Paladin was born!" << std::endl;

}

Paladin::~Paladin()
{
    std::cout << "   The life of " << name << " came to an end!" <<  std::endl << std::endl;

}

void Paladin::levelUp(){

    unsigned int counter = this->getLevel();    //stores the current level,

    Hero::levelUp();

    while(this->getLevel() > counter){  //if true then the hero leveled up when Hero::levelUp() was called
        counter++;
        increaseStrength(8);    // +8 strength per level
        increaseDexterity(2);   // +2 dexterity per level
        if(this->getLevel() % 3 == 0)
            increaseAgility(1);     //+1 agility every 3rd level
    }

}
