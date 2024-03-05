#include "Weapon.h"

Weapon::Weapon(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int damage,bool isTwoHanded)
    : Item(number,name,"Weapon",price,min_level),damage(damage),isTwoHanded(isTwoHanded)
{
    //ctor
}

unsigned int Weapon::getDamage() {

    return damage;

}

bool Weapon::IsTwoHanded() {

    return isTwoHanded;

}
