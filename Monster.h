#ifndef MONSTER_H
#define MONSTER_H

#include "Living.h"


class Monster : public Living
{
    public:
        Monster(std::string, unsigned int, int, unsigned int, unsigned int, unsigned int, unsigned int);
        virtual void showStats();
        unsigned int getDodgeChance();  //returns the chance to dodge a hero attack
        unsigned int getDamage();   //returns a damage value within the min and max damage range
        unsigned int getDefense();  //returns the damage reduction value

    protected:
        unsigned int min_damage;
        unsigned int max_damage;
        unsigned int defense;    // reduced damage taken from hero
        unsigned int dodgeChance;    // % chance to dodge a hero attack

    private:
};

#endif // MONSTER_H
