#include "Armor.h"

Armor::Armor(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int protection)
    : Item(number,name,"Armor",price,min_level),protection(protection)
{
    //ctor
}

unsigned int Armor::getProtection() {

    return protection; // returns protection of the armor

}
