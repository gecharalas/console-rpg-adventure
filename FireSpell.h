#ifndef FIRESPELL_H
#define FIRESPELL_H

#include "Spell.h"


class FireSpell : public Spell
{
    public:
        FireSpell(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int min_damage,
                  unsigned int max_damage,unsigned int energyCost,unsigned int, unsigned int);

    protected:

    private:
};

#endif // FIRESPELL_H
