#include <iostream>
#include <string>
#include "Potion.h"
#include "Item.h"

Potion::Potion(unsigned int number,std::string name,unsigned int price,unsigned int min_level,std::string Type,unsigned int value)
    : Item(number,name,"Potion",price,min_level),Type(Type),value(value)
{
    //ctor
}

unsigned int Potion::getStats() {

    return value;

}

std::string Potion::getType() {

    return Type;

}
