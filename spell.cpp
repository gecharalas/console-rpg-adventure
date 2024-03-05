#include <iostream>
#include "Spell.h"
#include <string>

Spell::Spell(unsigned int number,std::string name,std::string typeOfSpell,unsigned int price,unsigned int min_level,
             unsigned int min_damage,unsigned int max_damage,unsigned int energyCost,unsigned int duration, unsigned int effectPower)
    : number(number),name(name),typeOfSpell(typeOfSpell),price(price),min_level(min_level),min_damage(min_damage),
    max_damage(max_damage),energyCost(energyCost),duration(duration), effectPower(effectPower)
{
    //ctor
}

// Functions to get the information of every spell

std::string Spell::getTypeOfSpell() {

    return typeOfSpell;

}

unsigned int Spell::getNumber() {

    return number; // returns the number of the item

}

void Spell::setNumber(unsigned int num) {

    number = num;
}

std::string Spell::getName() {

    return name; // returns the name of the spell

}

unsigned int Spell::getPrice() {

    return price; // returns the price of the spell

}

unsigned int Spell::getMinLevel() {

    return min_level; // returns the minimum level required to equip this spell

}

unsigned int Spell::getMinDamage() {

    return min_damage; // returns the minimum damage that this spell can deal

}

unsigned int Spell::getMaxDamage() {

    return max_damage; // returns the maximum damage that this spell can deal

}

unsigned int Spell::getEnergyCost() {

    return energyCost; // returns the energy cost that this spell consume , every time we use it

}

unsigned int Spell::getDuration() {

    return duration;
}

unsigned int Spell::getEffectPower() {

    return effectPower;

}

