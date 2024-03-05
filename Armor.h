#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include <string>


class Armor : public Item
{
    public:
        Armor(unsigned int number,std::string name,unsigned int price,unsigned int min_level,unsigned int hp);
        unsigned int getProtection();

    protected:


    private:
        unsigned int protection;
};

#endif // ARMOR_H
