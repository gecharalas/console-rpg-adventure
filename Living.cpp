#include "Living.h"

Living::Living(std::string name, unsigned int level, int maxHealth)
:name(name), level(level), maxHealth(maxHealth), healthPower(maxHealth)
{
    //ctor
}

void Living::reduceHealth(unsigned int damage){

    healthPower = healthPower - damage;

}

int Living::getHealth(){

    return healthPower;

}

int Living::getMaxHealth(){

    return maxHealth;

}

unsigned int Living::getLevel() {

    return level;

}

void Living::setHealth(int a){

    healthPower = a;
    if(healthPower > maxHealth) healthPower = maxHealth;

}

std::string Living::getName(){

    return name;

}
