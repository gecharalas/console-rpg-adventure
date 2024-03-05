#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"


class Dragon : public Monster
{
    public:
        Dragon(unsigned int);
        virtual void showStats();

    protected:

    private:
};

#endif // DRAGON_H
