#ifndef SORCERER_H
#define SORCERER_H

#include "Hero.h"


class Sorcerer : public Hero
{
    public:
        Sorcerer(std::string);
        ~Sorcerer();
        virtual void levelUp();

    protected:

    private:
};

#endif // SORCERER_H
