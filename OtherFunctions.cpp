#include <iostream>
#include <ctime>


void delay(int a){
    time_t delay = time(NULL) + a;
    while (time(NULL) < delay){
        //waiting
    }
}

void clearScreen(){
    for(int i =0; i<100; i++){
        std::cout << std::endl;
    }
}
