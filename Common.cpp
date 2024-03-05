#include <iostream>
#include <cstdlib>

#include "Common.h"



Common::Common()
: GridTile("common"),monsterP(NULL)
{

}

Monster* Common::monster(){
    return monsterP;
}

bool Common::spawnMonster(unsigned int level){

    int spawnChance;

    spawnChance = rand() % 10;

    //Monster spawns
    if (spawnChance < 0){  // 30% chance to spawn a monster.
        int monsterType = rand() % 3;

        //Dragon
        if(monsterType == 0) monsterP = new Dragon(level);

        //Exosceleton
        else if(monsterType == 1) monsterP = new Exosceleton(level);

        //Spirit
        else monsterP = new Spirit(level);

        return true;

    }

    //Monster doesn't spawn
    return false;
}

void Common::deleteMonster(){

    if (monsterP != NULL) delete monsterP;

}


