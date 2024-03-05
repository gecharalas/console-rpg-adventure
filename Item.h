#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item
{
    public:
        Item(unsigned int number,std::string name,std::string typeOfItem,unsigned int price,unsigned int min_level);
        std::string getName();
        std::string getTypeOfItem();
        unsigned int getNumber();
        unsigned int getPrice();
        unsigned int getMinlevel();
        void setNumber(unsigned int);
        virtual unsigned int getDamage();
        virtual unsigned int getProtection();
        virtual unsigned int getStats();
        virtual std::string getType();
        virtual bool IsTwoHanded();

    protected:
        unsigned int number;
        std::string name;
        std::string typeOfItem;
        unsigned int price;
        unsigned int min_level;


    private:
};

#endif // ITEM_H
