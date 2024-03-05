#ifndef SPIRIT_H
#define SPIRIT_H

#include "Monster.h"


class Spirit : public Monster
{
    public:
        Spirit(unsigned int);
        virtual void showStats();

    protected:

    private:
};

#endif // SPIRIT_H
