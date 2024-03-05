#ifndef PALADIN_H
#define PALADIN_H

#include "Hero.h"


class Paladin : public Hero
{
    public:
        Paladin(std::string);
        ~Paladin();
        virtual void levelUp();

    protected:

    private:
};

#endif // PALADIN_H
