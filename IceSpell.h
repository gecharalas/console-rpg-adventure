#ifndef ICESPELL_H
#define ICESPELL_H

#include "Spell.h"


class IceSpell : public Spell
{
    public:
        IceSpell(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int min_damage,
                 unsigned int max_damage,unsigned int energyCost,unsigned int,unsigned int);

    protected:

    private:
};

#endif // ICESPELL_H
