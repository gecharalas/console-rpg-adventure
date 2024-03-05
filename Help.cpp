#include <iostream>



void help(){

    std::cout << std::endl << std::endl;
    std::cout << "Type the action you want to perform and hit 'Enter'" << std::endl;
    std::cout << "Available actions:" << std::endl;
    std::cout << "   w,a,s or d:  To move on the map" << std::endl;
    std::cout << "   inventory:  To view your inventory" << std::endl;
    std::cout << "   equip:  Brings up a menu to equip or un-equip item(s)" << std::endl;
    std::cout << "   use:  To use a potion" << std::endl;
    std::cout << "   stats:  To view hero stats" << std::endl;
    std::cout << "   quit: To quit game" << std::endl <<  std::endl;

}
