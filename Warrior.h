#ifndef WARRIOR_H
#define WARRIOR_H

#include "Hero.h"


class Warrior : public Hero
{
    public:
        Warrior(std::string);
        ~Warrior();
        virtual void levelUp();

    protected:

    private:
};

#endif // WARRIOR_H
