#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Grid.h"
#include "Market.h"

using namespace std;

void help();
void play(Grid&);
void intro(Grid&);
void outro(Grid&);

int main()
{
    srand(time(NULL));
    Grid grid;
    intro(grid);
    play(grid);
    outro(grid);

}
