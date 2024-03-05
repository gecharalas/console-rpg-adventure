#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "Grid.h"
#include "Hero.h"




void help();
void clearScreen();
void delay(int);


void play(Grid& grid){

    std::string input;
    std::cin >> input;

    while(input != "quit"){

        //Moving inputs
        if(input == "w") {
            clearScreen();
            grid.move(input);
        }
        else if(input == "a") {
            clearScreen();
            grid.move(input);
        }
        else if(input == "s") {
            clearScreen();
            grid.move(input);
        }
        else if(input == "d") {
            clearScreen();
            grid.move(input);
        }

        else if (input == "inventory") {

            std::string choice;

            Hero* hero = grid.hero();

            choice = hero->Menu();

            while (choice != "3") {
                if (choice=="1") {
                    if (hero->getItemsInventory().size()==0) {
                        std::cout << "\nITEMS INVENTORY IS EMPTY!" << std::endl << std::endl;
                        choice = hero->Menu();
                    }
                    else {
                        hero->showItemsInventory();
                        choice = hero->Menu();

                    }
                }
                else {

                    if (hero->getSpellsInventory().size()==0) {
                        std::cout << "\nSPELLS INVENTORY IS EMPTY!" << std::endl << std::endl;
                        choice = hero->Menu();
                    }
                    else {
                        hero->showSpellsInventory();
                        choice = hero->Menu();
                    }

                }

            }

            if (choice == "3") {
                std::cout << "Transitioning back to the map.." ;
                delay(2);
                clearScreen();
                grid.displayMap();
            }


        }
        else if (input == "equip") {
            clearScreen();
            std::string choice;
            Hero* hero = grid.hero();

            choice = hero->EquipUnEquipMenu();

            while (choice!="3") {
                if (choice=="1") {
                    hero->equip();
                    choice = hero->EquipUnEquipMenu();
                }
                else {
                    hero->unequip();
                    choice = hero->EquipUnEquipMenu();
                }
            }
            if (choice=="3") {
                std::cout << "Transitioning back to the map.." ;
                delay(2);
                clearScreen();
                grid.displayMap();
            }
        }


        //Help please :/
        else if(input == "help"){
           help();
           grid.displayMap();
           }

        else if(input == "stats"){
            clearScreen();
            grid.hero()->showStats();
            delay(3);
            grid.displayMap();

        }

        else if (input == "use") {
            Hero* hero = grid.hero();
            hero->usePotion();
            delay(1);
            grid.displayMap();

        }


        //Invalid Input
        else{
            std::cout << "Invalid input , please try again !" << std::endl;
            std::cout << "Type 'help' to get info on the available actions." << std::endl << std::endl;
        }



        //Taking new input
        std::cin >> input;

    }


}
