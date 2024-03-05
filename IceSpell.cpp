#include "IceSpell.h"

IceSpell::IceSpell(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int min_damage,
                   unsigned int max_damage,unsigned int energyCost,unsigned int duration,unsigned int effectPower)
    : Spell(number,name,"ice",price,min_level,min_damage,max_damage,energyCost,duration,effectPower)
{
    //ctor
}
