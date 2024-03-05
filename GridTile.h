#ifndef GRIDTILE_H
#define GRIDTILE_H
#include "Living.h"
#include "Monster.h"
#include "Hero.h"
#include <string>


class GridTile
{
    public:
        GridTile(std::string tileType);
        virtual void show_Items_Spells(Hero* hero);
        std::string getTileType();
        virtual bool spawnMonster(unsigned int);
        virtual Monster* monster();
        virtual void deleteMonster();

    protected:
        std::string tileType;  // market,common, or nonAccessible

    private:
};

#endif // GRIDTILE_H


