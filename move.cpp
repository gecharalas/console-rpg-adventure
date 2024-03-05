#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Grid.h"
#include "Market.h"
#include "Common.h"
#include "NonAccessible.h"
#include "Warrior.h"
#include "Sorcerer.h"
#include "Paladin.h"

void fight(Hero*,Monster*);

void Grid::monsterEncounter(){

    //A monster does spawn
    if(Map[x][y]->spawnMonster(hero()->getLevel()) == true){
        fight(hero(),Map[x][y]->monster());

    }

}

void Grid::move(std::string direction){

    //Moving up
    if(direction=="w"){
        if (x==0){
            std::cout << "Can't go out of map. Try a different direction." << std::endl;
        }else{

            //Common
            if(Map[x-1][y]->getTileType() == "common"){
                x-=1;
                monsterEncounter();
                Map[x][y]->deleteMonster();
                this->displayMap();

            //Market
            }else if(Map[x-1][y]->getTileType() == "market"){
                x-=1;
                this->displayMap();
                Map[x][y]->show_Items_Spells(heroP);
                this->displayMap();

            //nonAccessible
            }else{
                this->displayMap();
                std::cout << "Sorry!This square is non-accessible!" << std::endl;
            }
        }


    //Moving left
    }else if(direction=="a"){
        if (y==0){
            std::cout << "Can't go out of map. Try a different direction." << std::endl;
        }else{

            //Common
            if(Map[x][y-1]->getTileType() == "common"){
                y-=1;
                monsterEncounter();
                Map[x][y]->deleteMonster();
                this->displayMap();

            //Market
            }else if(Map[x][y-1]->getTileType() == "market"){
                y-=1;
                this->displayMap();
                Map[x][y]->show_Items_Spells(heroP);
                this->displayMap();

            //NonAccessible
            }else{
                this->displayMap();
                std::cout << "Sorry!This square is non-accessible!" << std::endl;
            }
        }


    //Moving down
    }else if(direction=="s"){
        if (x==9){
            std::cout << "Can't go out of map. Try a different direction." << std::endl;
        }else{

            //Common
            if(Map[x+1][y]->getTileType() == "common"){
                x+=1;
                monsterEncounter();
                Map[x][y]->deleteMonster();
                this->displayMap();

            //Market
            }else if(Map[x+1][y]->getTileType() == "market"){
                x+=1;
                this->displayMap();
                Map[x][y]->show_Items_Spells(heroP);
                this->displayMap();

            //nonAccessible
            }else{
                this->displayMap();
                std::cout << "Sorry!This square is non-accessible!" << std::endl;
            }
        }


    //Moving right
    }else{
        if (y==19){
            std::cout << "Can't go out of map. Try a different direction." << std::endl;
        }else{

            //Common
            if(Map[x][y+1]->getTileType() == "common"){
                y+=1;
                monsterEncounter();
                Map[x][y]->deleteMonster();
                this->displayMap();

            //Market
            }else if(Map[x][y+1]->getTileType() == "market"){
                y+=1;
                this->displayMap();
                Map[x][y]->show_Items_Spells(heroP);
                this->displayMap();

            //Non Accessible
            }else{
                this->displayMap();
                std::cout << "Sorry!This square is non-accessible!" << std::endl;
            }
        }
    }

}
