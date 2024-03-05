#ifndef SPELL_H
#define SPELL_H

#include <string>


class Spell
{
    public:
        Spell(unsigned int,std::string,std::string,unsigned int,unsigned int,
              unsigned int ,unsigned int ,unsigned int,unsigned int,unsigned int);
        std::string getName();
        std::string getTypeOfSpell();
        unsigned int getNumber();
        unsigned int getPrice();
        unsigned int getMinLevel();
        unsigned int getMinDamage();
        unsigned int getMaxDamage();
        unsigned int getEnergyCost();
        unsigned int getDuration();
        unsigned int getEffectPower();

        void setNumber(unsigned int);

    protected:
        unsigned int number;
        std::string name;
        std::string typeOfSpell;
        unsigned int price;
        unsigned int min_level;
        unsigned int min_damage;
        unsigned int max_damage;
        unsigned int energyCost;
        unsigned int duration;  //Duration of spell effect
        unsigned int effectPower;   // value of the spell effect


    private:
};

#endif // SPELL_H
