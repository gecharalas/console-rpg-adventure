#ifndef MARKET_H
#define MARKET_H
#include <vector>

#include "GridTile.h"
#include "Item.h"
#include "Spell.h"
#include "Hero.h"



class Market : public GridTile

{
 public:
        Market();
        unsigned int ItemOrSpell();
        bool Item_Requirements(Hero*,Item*);
        bool Spell_Requirements(Hero*,Spell*);
        void show_Items_Spells(Hero*);
        void show_Items(unsigned int);
        void show_Spells();
        void buy(Hero*);
        void sell(Hero*);
        void sellEquipped(Hero*);
        std::string sellInvOrEquipped();
        std::string Market_Menu();


    private:

        std::vector<Item*> Items;
        std::vector<Spell*> Spells;


};





#endif // MARKET_H
