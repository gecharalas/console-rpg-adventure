#ifndef LIVING_H
#define LIVING_H
#include <string>


class Living
{
    public:
        Living(std::string, unsigned int, int);
        void reduceHealth(unsigned int);
        int getHealth();
        int getMaxHealth();
        unsigned int getLevel();
        void setHealth(int);
        std::string getName();

    protected:
        std::string name;
        unsigned int level;
        int healthPower;   // Current health value. When healthPower <= 0 the living creature dies.
        int maxHealth;    // Max health value.

    private:
};

#endif // LIVING_H


