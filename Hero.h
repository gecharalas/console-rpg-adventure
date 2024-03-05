#ifndef HERO_H
#define HERO_H
#include <vector>

#include "Living.h"
#include "Item.h"
#include "Spell.h"



class Hero : public Living
{
    public:
        Hero(std::string name, unsigned int strength, unsigned int dexterity, unsigned int agility);
        virtual ~Hero();
        virtual void levelUp();
        int expToNextLevel();
        void increaseExp(unsigned int);
        void increaseMoney(unsigned int);
        void increaseStrength(unsigned int);
        void increaseDexterity(unsigned int);
        void increaseAgility(unsigned int);
        void setMagicPower(unsigned int);
        void showBattleStats();
        void showStats();
        void setMoney(unsigned int cost);
        void usePotion();
        void equip();
        void unequip();
        void setItemsInventory(Item* address);
        void setSpellsInventory(Spell* address);
        void showItemsInventory();
        void showSpellsInventory();
        void showSpellsBattle();
        void SellItem(unsigned int);
        void SellSpell(unsigned int);
        void MovingEquippedItems(std::string);
        void SettingInvNumber();
        void AddDamage(unsigned int);
        void AddProtection(unsigned int);
        void reduceDamage(unsigned int);
        void reduceProtection(unsigned int);
        void setRightHand();
        void setLeftHand();
        void sellEquipped(std::string);
        bool showEquippedItems();
        bool showPotions();
        bool foundPotion(unsigned int);

        unsigned int getMoney();
        unsigned int getMagicPower();
        unsigned int getDamage();   //returns the total hero damage(strength+weapon)
        unsigned int getDodgeChance();  //returns the chance to dodge a monster attack
        unsigned int getSpellDamage(Spell*);  //returns the total spell damage of the desired spell.
        unsigned int getDefense();  //returns the damage reduction value from the hero's armor
        std::string Menu();
        Item* getRightHand();
        Item* getLeftHand();

        std::vector<Item*> getItemsInventory();
        std::vector<Spell*> getSpellsInventory();
        std::string StoreOrDrop();
        std::string asking();
        std::string ask_ing();
        std::string WeaponOrArmor();
        std::string EquipUnEquipMenu();



    protected:
        unsigned int magicPower;   // Current value of magic power.
        unsigned int maxMagicPower;   // Max value of magic power
        unsigned int strength;    //Damage dealt to the enemies. 1 point in strength is equal to 1 damage.
        unsigned int dexterity;    //Spell damage = min_damage + (max_damage-min_damage)*(dexterity/100)
        unsigned int agility;     // % chance to dodge an enemy attack
        unsigned int money;
        unsigned int experience;
        unsigned int armor;
        Item* right_hand; // hero's right hand
        Item* left_hand; // hero's left hand
        std::vector<Item*> Items; // hero's potions
        //std::vector<Spell*> Spells; // hero's spells
        std::vector<Item*> ItemsInventory; // hero's inventory for items
        std::vector<Spell*> SpellsInventory; // hero's inventory for spells

    private:
};

#endif // HERO_H

