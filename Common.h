#ifndef COMMON_H
#define COMMON_H

#include "GridTile.h"
#include "Dragon.h"
#include "Exosceleton.h"
#include "Spirit.h"


class Common : public GridTile
{
    public:
        Common();
        Monster* monster();
        bool spawnMonster(unsigned int);
        void deleteMonster();

    protected:


    private:
        Monster* monsterP;

};

#endif // COMMON_H
