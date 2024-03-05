#ifndef LIGHTINGSPELL_H
#define LIGHTINGSPELL_H

#include "Spell.h"


class LightingSpell : public Spell
{
    public:
        LightingSpell(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int min_damage,
                      unsigned int max_damage,unsigned int energyCost,unsigned int,unsigned int);

    protected:

    private:
};

#endif // LIGHTINGSPELL_H
