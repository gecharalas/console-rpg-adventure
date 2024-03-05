#include <iostream>
#include "GridTile.h"


GridTile::GridTile(std::string tileType) : tileType(tileType)
{

}

std::string GridTile::getTileType(){
    return tileType;
}

void GridTile::show_Items_Spells(Hero* hero) {}


bool GridTile::spawnMonster(unsigned int) {}

void GridTile::deleteMonster() {}

Monster* GridTile::monster(){}
