#include <iostream>
#include <time.h>
#include "Grid.h"


void delay(int);
void clearScreen();

//A small little intro sequence
void intro(Grid& grid){


    grid.hero()->showStats();

    delay(1);
    std::cout << "Loading map in 3..." ;
    std::flush(std::cout);

    //Kinda animated...

    delay(1);
    std::cout << "  2..." ;
    std::flush(std::cout);
    delay(1);
    std::cout << "  1..." ;
    std::flush(std::cout);
    delay(1);
    grid.displayMap();

}


//An outro sequence with credits!
void outro(Grid& grid){

    clearScreen();
    std::cout << "   Quitting game..." << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << "   Created by:" << std::endl;
    std::cout << '\t' << "Giorgos Charalampidis" << std::endl;
    std::cout << '\t' << "Karolos Giampouonka Kanellakos" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << "   Thanks for playing our game!" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << "   Hope you liked it!" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "   The world is collapsing..." << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
    delay(1);
    std::cout << std::endl << std::endl << std::endl;
}
