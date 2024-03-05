#include <iostream>
#include "IceSpell.h"
#include "Hero.h"

Hero::Hero(std::string name, unsigned int strength, unsigned int dexterity, unsigned int agility)
:Living(name, 20, 100), magicPower(10), maxMagicPower(10), strength(strength), dexterity(dexterity), agility(agility), money(2000), experience(0),armor(0),
left_hand(NULL),right_hand(NULL)

{


}

Hero::~Hero() {}

int Hero::expToNextLevel(){
    return ( 10 * ( 2 << (level - 1)) - 10 );

}

void Hero::levelUp(){
    while(experience >= this->expToNextLevel()){
        level++;
        std::cout << "Your hero leveled up! You are now level " << level << std::endl;
        std::cout << "Your hero is getting stronger!" << std::endl << std::endl;

        //Increasing the max health.
        maxHealth += 50;

        //Refilling health and magic power.
        healthPower = maxHealth;
        magicPower = maxMagicPower;
    }
}


//Prints the current Health and Magic Power values.
void Hero::showBattleStats(){
    std::cout << std::endl;
    std::cout << "Hero stats: " << std::endl << std::endl;
    std::cout << "Health: " << healthPower << "/" << maxHealth << std::endl;
    std::cout << "Magic Power: " << magicPower << "/" << maxMagicPower << std::endl;
}

//Prints all hero stats
void Hero::showStats(){
    this->showBattleStats();
    std::cout << "Level: " << level << std::endl;
    std::cout << "Experience: " << experience << "/" << this->expToNextLevel() << std::endl;
    std::cout << "Gold: " << money << std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << "Armor: " << armor << std::endl;
    std::cout << "Dexterity: " << dexterity << std::endl;
    std::cout << "Agility: " << agility << std::endl;
    //std::cout << "Items Inventory space: 4" << std::endl;
    //std::cout << "Spells Inventory space: 4" << std::endl;
    std::cout << std::endl;
}


std::vector<Item*> Hero::getItemsInventory() {

    return ItemsInventory;

}

std::vector<Spell*> Hero::getSpellsInventory() {

    return SpellsInventory;

}


unsigned int Hero::getMoney() {

    return money; // returns hero's money

}


void Hero::setItemsInventory(Item* address) {
        ItemsInventory.push_back(address);
       // std::vector<Item*>::iterator it = ItemsInventory.end()-1;
        std::cout << "\nCongratulations ! " ;
        std::flush(std::cout);
        std::cout <<  address->getName() ;
        std::flush(std::cout);
        std::cout << " is now yours!" << std::endl;
        address->setNumber(ItemsInventory.size());
}

void Hero::setSpellsInventory(Spell* address) {
        SpellsInventory.push_back(address);

        std::cout << "\nCongratulations ! " ;
        std::flush(std::cout);
        std::cout <<  address->getName() ;
        std::flush(std::cout);
        std::cout << " is now yours!" << std::endl;
        address->setNumber(SpellsInventory.size());

}

void Hero::setMoney(unsigned int price) {

    money -= price;

}

void Hero::showItemsInventory() {

    std::vector<Item*>::iterator it;
    std::cout << "**********************************************  Hero's Items Inventory  **********************************************" << std::endl << std::endl;

    for (it=ItemsInventory.begin();it!=ItemsInventory.end();it++) {

       if ((*it)->getTypeOfItem()=="Weapon") {
            std::cout <<(*it)->getNumber() << "." << " " ;
            std::cout << "Type: " << (*it)->getTypeOfItem() << '\t';
            std::cout << "Name: " << (*it)->getName() << '\t' ;
            std::cout << "Damage:" << (*it)->getDamage() ;
            if ((*it)->IsTwoHanded()==1) std::cout << '\t' << "Two-Handed" << '\t';
            else std::cout << '\t' << "One-Handed" << '\t';
            std::cout << "MinLvl required: " << (*it)->getMinlevel() << '\t' ;
            std::cout << "Price: " << (*it)->getPrice() << " gold" << std::endl << std::endl;
       }
       else if ((*it)->getTypeOfItem()=="Armor") {
            std::cout << (*it)->getNumber() << "." << " " ;
            std::cout << "Type: " << (*it)->getTypeOfItem() << '\t';
            std::cout << "Name: " << (*it)->getName() << '\t' ;
            std::cout << "Protection: " << (*it)->getProtection() << '\t';
            std::cout << "MinLvl required: " << (*it)->getMinlevel() << '\t';
            std::cout << "Price: " << (*it)->getPrice() << " gold" << std::endl << std::endl;
       }
       else {
            std::cout << (*it)->getNumber() << "." << " " ;
            std::cout << "Type: " << (*it)->getTypeOfItem() << '\t';
            std::cout << "Name: " << (*it)->getName() << '\t' ;
            std::cout << "MinLvl required: " << (*it)->getMinlevel() << '\t';
            std::cout << "Price: " << (*it)->getPrice() << " gold" << std::endl << std::endl;

       }
    }

}

void Hero::showSpellsInventory() {
    unsigned int StringL;
    std::vector<Spell*>::iterator it;
    std::cout << "**********************************************  Hero's Spells  **********************************************" << std::endl;

    for (it=SpellsInventory.begin();it!=SpellsInventory.end();it++) {

            StringL = (*it)->getName().length();
            std::cout << (*it)->getNumber() << "." << " " ;
            std::cout << "Name: " ;
            if (StringL<=7) std::cout << (*it)->getName() << '\t' << '\t';
            else if  (StringL>7 && StringL<15) std::cout << (*it)->getName() << '\t';
            else std::cout << (*it)->getName()  ;
            std::cout << "Type: " << (*it)->getTypeOfSpell() << '\t';
            std::cout << "MinDmg:" << (*it)->getMinDamage() << '\t' << "MaxDmg: " << (*it)->getMaxDamage() << '\t';
            std::cout << "Duration: " << (*it)->getDuration() << '\t';
            std::cout << "EffectPower: " << (*it)->getEffectPower() << '\t' << '\t';
            std::cout << "MinLvl: " << (*it)->getMinLevel() << '\t';
            std::cout << "Energy:" << (*it)->getEnergyCost() << '\t';
            std::cout << "Price: " << (*it)->getPrice() << std::endl;

    }

}

void Hero::SellItem(unsigned int number) {

    unsigned int SellingPrice;
    unsigned int num=1;

    std::vector<Item*>::iterator it=ItemsInventory.begin();
    std::advance(it,number-1);
    SellingPrice = (*it)->getPrice()/2;

    std::cout << (*it)->getName() << " was sold for " << SellingPrice << " gold" << std::endl;
    money += SellingPrice;
    std::cout << "Your new balance is : " << money << " gold" << std::endl;
    ItemsInventory.erase(it);

    for (it=ItemsInventory.begin();it!=ItemsInventory.end();it++) {

            (*it)->setNumber(num);
            num++;

    }
}

void Hero::SellSpell(unsigned int number) {

    unsigned int SellingPrice;
    unsigned int num=1;

    std::vector<Spell*>::iterator it=SpellsInventory.begin();
    std::advance(it,number-1);
    SellingPrice = (*it)->getPrice()/2;

    std::cout << (*it)->getName() << " was sold for " << SellingPrice << " gold" << std::endl;
    money += SellingPrice;
    std::cout << "Your new balance is : " << money << " gold" << std::endl;
    SpellsInventory.erase(it);

    for (it=SpellsInventory.begin();it!=SpellsInventory.end();it++) {

            (*it)->setNumber(num);
            num++;
    }

}


unsigned int Hero::getDamage(){


    return strength;


}


unsigned int Hero::getDodgeChance(){

    return agility;

}

unsigned int Hero::getSpellDamage(Spell* spell){

    unsigned int spellDamage;

    //Spell damage = min_damage + (max_damage-min_damage)*(dexterity/100)

    spellDamage = spell->getMinDamage() + ((spell->getMaxDamage() - spell->getMinDamage())*dexterity) / 100;

    return spellDamage;

}

bool Hero::showEquippedItems() {

    if (right_hand == NULL && left_hand == NULL)  {
        std::cout << "**********  NO ITEMS ARE CURRENTLY EQUIPPED  **********" << std::endl << std::endl;
        return false;
    }
    else {
        std::cout << "******************************  Equipped Items  ******************************" << std::endl;
        if (right_hand!=NULL && left_hand == NULL) std::cout << right_hand->getName() << " on your right hand!" << std::endl << std::endl;
        else if (right_hand == NULL && left_hand != NULL) std::cout << left_hand->getName() << " on your left hand!" << std::endl << std::endl;
        else if (right_hand!=NULL && left_hand!=NULL) {

            if (right_hand->getName() == left_hand->getName()) std::cout << right_hand->getName() << " on both of your hands!" << std::endl << std::endl;
            else std::cout << right_hand->getName() << " on your right hand & " << left_hand->getName() << " on your left hand!" << std::endl << std::endl;

        }
      return true;
    }

}

unsigned int Hero::getDefense(){

    return armor;

}

void Hero::increaseExp(unsigned int a){

    experience += a;

}


void Hero::increaseMoney(unsigned int a){

    money += a;

}

void Hero::increaseStrength(unsigned int a){

    strength += a;
}


void Hero::increaseDexterity(unsigned int a){

    dexterity +=a;

}

void Hero::increaseAgility(unsigned int a){

    agility += a;

}


void Hero::setMagicPower(unsigned int a){

    magicPower = a;
    if (magicPower > maxMagicPower) magicPower = maxMagicPower;

}

unsigned int Hero::getMagicPower(){

    return magicPower;

}


void Hero::showSpellsBattle() {
    unsigned int StringL;
    std::vector<Spell*>::iterator it;
    std::cout << "**********************************************  Hero's Spells  **********************************************" << std::endl;

    for (it=SpellsInventory.begin();it!=SpellsInventory.end();it++) {

            StringL = (*it)->getName().length();
            std::cout << (*it)->getNumber() << "." << " " ;
            std::cout << "Name: " ;
            if (StringL<=7) std::cout << (*it)->getName() << '\t' << '\t';
            else if  (StringL>7 && StringL<15) std::cout << (*it)->getName() << '\t';
            else std::cout << (*it)->getName()  ;
                std::cout << "Type: " << (*it)->getTypeOfSpell() << '\t';
                std::cout << "MinDmg: " << (*it)->getMinDamage() << '\t' << "MaxDmg: " << (*it)->getMaxDamage() << '\t';
                std::cout << "Dur: " << (*it)->getDuration() << '\t'; // Duration
                std::cout << "EPower: " << (*it)->getEffectPower() << '\t' << "   " ; // EffectPower
                std::cout << "Energy: " << (*it)->getEnergyCost() << std::endl << '\t';
            if((*it)->getTypeOfSpell() == "fire"){
                std::cout << "Reduces the enemy's defense value by " << (*it)->getEffectPower() << "% for " << (*it)->getDuration() << " rounds!" << std::endl;
            }
            else if((*it)->getTypeOfSpell() == "ice"){
                std::cout << "Reduces the enemy's attack by " << (*it)->getEffectPower() << "% for " << (*it)->getDuration() << " rounds!" << std::endl;
            }
            else{
                std::cout << "Reduces the enemy dodge chance by " << (*it)->getEffectPower() << "% for " << (*it)->getDuration() << " rounds!" << std::endl;
            }

            std::cout << std::endl <<std::endl;
    }

}


