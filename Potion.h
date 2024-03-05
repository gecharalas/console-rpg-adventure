#ifndef POTION_H
#define POTION_H
#include <string>

#include "Item.h"


class Potion : public Item
{
    public:
        Potion(unsigned int number,std::string name,unsigned int price,unsigned int min_level,std::string,unsigned int value);
        unsigned int getStats();
        std::string getType();

    private:

        std::string Type;
        unsigned int value;

};

#endif // POTION_H
