#ifndef GRID_H
#define GRID_H
#include "GridTile.h"
#include "Hero.h"


class Grid
{
    public:
        Grid();
        ~Grid();
        void move(std::string);
        void displayMap();
        Hero* hero();
        std::string Hero_Selection();


    protected:


    private:

        GridTile* Map[10][20];
        unsigned int heroCount;
        Hero* heroP;
        void monsterEncounter();
        unsigned int x;    // x  of the hero.
        unsigned int y;    // y coordinates of the hero.

};

#endif // GRID_H
