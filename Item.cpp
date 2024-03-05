#include <iostream>
#include <string>
#include "Item.h"

Item::Item(unsigned int number,std::string name,std::string typeOfItem,unsigned int price,unsigned int min_level)
    : number(number),name(name),typeOfItem(typeOfItem),price(price),min_level(min_level)

{
    //ctor
}

std::string Item::getName() {

    return name; // returns the name of the item

}

std::string Item::getTypeOfItem() {

    return typeOfItem; // returns the type of the item (weapon,armor,potion)
}

std::string Item::getType() {} // virtual to get type of Potion


unsigned int Item::getNumber() {

    return number; // returns the number of the item

}


unsigned int Item::getPrice() {

    return price; // returns the price of the item

}

unsigned int Item::getMinlevel() {

    return min_level; // return the min_level required to equip this item

}

void Item::setNumber(unsigned int num) {

    number = num;
}



unsigned int Item::getDamage() {}

unsigned int Item::getProtection() {}

unsigned int Item::getStats() {}

bool Item::IsTwoHanded() {}
