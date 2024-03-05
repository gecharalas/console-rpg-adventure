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

void help();

Grid::Grid() : x(1),y(1)
{
    // Creating the map
    for (int i=0;i<10;i++) {
        for (int j=0;j<20;j++) {
            // Creating Non Accesible gridtiles
            if (j==0 || i==0 || i==9 || j==19) Map[i][j] = new NonAccessible();
            if ((i==1 || i==2 || i==7 || i==8) && (j>=9 || j <=12)) Map[i][j] = new NonAccessible();
            // Creating the two markets of the map
            Map[7][2] = new Market();
            Map[2][17] = new Market();
            // Creating the common gridtiles
            if (i==1 && ((j>=1 && j<=8) || (j>=13 && j<=18))) Map[i][j] = new Common();
            if (i==2 && ((j>=1 && j<=8) || (j>=13 && j<=16) || j==18)) Map[i][j] = new Common();
            if (i>=3 && i<=6 && j>=1 && j<=18) Map[i][j] = new Common();
            if (i==7 && (j==1 || (j>=3 && j<=8) || (j>=13 && j<=18))) Map[i][j] = new Common();
            if (i==8 && ((j>=1 && j<=8) || (j>=13 && j<=18))) Map[i][j] = new Common();

        }

    }


    //Selecting hero type

    std::string selection;
    selection = Hero_Selection();
    std::cin.clear();
    fflush(stdin);

    //Selecting your hero's name
    std::string name;
    std::cout << "Type your hero's name!" << std::endl;
    std::cin >> name;
    std::cout << std::endl << std::endl;

    if (selection=="1") heroP = new Warrior(name);
    else if (selection=="2") heroP = new Sorcerer(name);
    else heroP = new Paladin(name);


}

Grid::~Grid() {
    //Destroying the hero
    delete heroP;
    //Destroying the map
    for (int i=0;i<10;i++) {

        for (int j=0;j<20;j++) {

                delete Map[i][j];
        }

    }
}


void Grid::displayMap(){
    std::cout << std::endl << std::endl << "   _ = Common Square   M = Market   # = Non Accessible Square" << std::endl;
    std::cout << '\t' ;
    //for (unsigned int j= 0; j<20;j++) std::cout << " _" ;
    std::cout << std::endl;
    for (unsigned int i=0;i<10;i++) {
            std::cout << '\t' << "|" ;
        for (unsigned int j=0;j<20;j++) {
            if(i==x && j==y){ std::cout << "X" ;
            }else{
                if(Map[i][j]->getTileType() == "common"){
                    std::cout << "_" ;
                }else if(Map[i][j]->getTileType() == "market"){
                    std::cout << "M" ;
                }else{
                    std::cout << "#" ;
                }
            }
            std::cout << "|" ;
        }
        std::cout << std::endl ;
    }
    std::cout << std:: endl << std::endl;
    std::cout << "Type 'help' to get info on the available actions." << std::endl;
    std::cout << std:: endl << std::endl;
}

std::string Grid::Hero_Selection() {

    std::string choice;

    std::cout << "***********************\n\n" ;
    std::cout << "Hero Selection\n";
    std::cout << "1 - Warrior\n";
    std::cout << "2 - Sorcerer\n";
    std::cout << "3 - Paladin\n\n";
    std::cout << "***********************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl ;

    while (choice!="1" && choice!="2" && choice!="3") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }

    return choice;

}

Hero* Grid::hero(){
    return heroP;
}
