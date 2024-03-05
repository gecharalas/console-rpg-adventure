#include <iostream>
#include "Sorcerer.h"

Sorcerer::Sorcerer(std::string name)
:Hero(name, 13, 16, 10)
{
    std::cout << name << " the Sorcerer was born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << "   The life of " << name << " came to an end!" <<  std::endl << std::endl;

}

void Sorcerer::levelUp(){

    unsigned int counter = this->getLevel();    //stores the current level,

    Hero::levelUp();

    while(this->getLevel() > counter){  //if true then the hero leveled up when Hero::levelUp() was called
        counter++;
        increaseStrength(5);    // +5 strength per level
        increaseDexterity(2);   // +2 dexterity per level
        if(this->getLevel() % 2 == 0)
            increaseAgility(1);     //+1 agility every 2nd level
    }

}
