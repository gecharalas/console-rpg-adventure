#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <string>


class Weapon : public Item
{
    public:
        Weapon(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int damage,bool isTwoHanded);
        unsigned int getDamage();
        bool IsTwoHanded();

    protected:

    private:
        unsigned int damage;
        bool isTwoHanded;
};

#endif // WEAPON_H
