#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "Market.h"
#include "GridTile.h"
#include "FireSpell.h"
#include "IceSpell.h"
#include "LightingSpell.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "VStrings.h"

void clearScreen();
void delay(int);

using namespace LoveIsInTheAir;

Market::Market()
    : GridTile("market")

{

    std::fstream weapons("weapons.txt");
    std::fstream potions("potions.txt");
    std::fstream armors("armors.txt");
    std::fstream spells("spells.txt");

    for (int i=0;i<30;i++) {

        Level = rand()%(maxLevel-minLevel + 1) + minLevel;
        WeaponPrice = rand()%(maxWeaponPrice-minWeaponPrice + 1) + minWeaponPrice;
        SpellPrice = rand()%(maxSpellPrice-minSpellPrice + 1) + minSpellPrice;
        Damage = Level * (rand()%(maxDamage-minDamage + 1)) + minDamage * (Level-1);
        Dexterity = Level * (rand()%(maxDexterity-minDexterity + 1)) + minDexterity * (Level -1);
        Agility = Level * (rand()%(maxAgility-minAgility + 1)) + minAgility * (Level -1);
        Health = Level * (rand()%(maxHealth-minHealth + 1)) + minHealth * (Level-1);
        minSpellDamage = Level * minSpellDamagePerLevel + Level * (rand() % 5) + rand() % 3;
        maxSpellDamage = Level * maxSpellDamagePerLevel + Level * ((rand() % 10) + 1) + rand() % 5;
        Protection = Level * (rand()%(maxProtection-minProtection +1) + 1) + minProtection;
        EnergyCost= rand()%(maxEnergyCost-minEnergyCost + 1) + minEnergyCost;
        isTwoHanded = rand() % 2;
        Duration = rand() % (maxDuration - minDuration + 1) + minDuration;
        DamageReduction = rand() % (maxDamageReduction - minDamageReduction + 1) + minDamageReduction;
        DodgeChanceReduction = rand() % (maxDodgeChanceReduction - minDodgeChanceReduction + 1) + minDodgeChanceReduction;
        DefenseReduction = rand() % (maxDefenseReduction - minDefenseReduction + 1) + minDefenseReduction;

        std::getline(spells,Fspellname,'\n');
        std::getline(spells,Lspellname,'\n');
        std::getline(spells,Ispellname,'\n');
        std::getline(weapons,Wname,'\n');
        std::getline(armors,Aname,'\n');
        std::getline(potions,Pname,'\n');

        if (i<10) {
            // Creating Weapons

            Items.push_back(new Weapon(i+1,Wname,WeaponPrice,Level,Damage,isTwoHanded));

            // Creating Fire Spell

            Spells.push_back(new FireSpell(i+1,Fspellname,SpellPrice,Level,minSpellDamage,maxSpellDamage,EnergyCost,Duration,DefenseReduction));


        }
        else if (i>=10 && i<20) {
            // Creating Armors

            Items.push_back(new Armor(i+1,Aname,WeaponPrice,Level,Protection));

            // Creating Lighting Spell

            Spells.push_back(new LightingSpell(i+1,Lspellname,SpellPrice,Level,minSpellDamage,maxSpellDamage,EnergyCost,Duration,DodgeChanceReduction));

        }
        else {
            // Creating Potions
            if (i<24) Items.push_back(new Potion(i+1,Pname,WeaponPrice,Level,"Health",Health));
            else if (i>=24 && i<26) Items.push_back(new Potion(i+1,Pname,WeaponPrice,Level,"Damage",Damage));
            else if (i>=26 && i<28) Items.push_back(new Potion(i+1,Pname,WeaponPrice,Level,"Agility",Agility));
            else Items.push_back(new Potion(i+1,Pname,WeaponPrice,Level,"Dexterity",Dexterity));
            // Creating Ice Spells

            Spells.push_back(new IceSpell(i+1,Ispellname,SpellPrice,Level,minSpellDamage,maxSpellDamage,EnergyCost,Duration,DamageReduction));

        }



    }

}



void Market::show_Items_Spells(Hero* hero){

  std::string Display;

  Display = Market_Menu();



  while(Display!="7") {

        if (Display=="1") {
            this->show_Items(1);
            Display = Market_Menu();
        }
        else if (Display=="2") {
            this->show_Items(2);
            Display = Market_Menu();

        }
        else if (Display=="3") {
            this->show_Items(3);
            Display = Market_Menu();
        }
        else if (Display=="4") {
            this->show_Spells();
            Display = Market_Menu();

        }
        else if (Display=="5") {
            this->buy(hero);
            Display = Market_Menu();
        }
        else {
            this->sell(hero);
            Display = Market_Menu();

        }

  }

  if (Display=="7") {
    std::cout << "Exiting market ." ;
    delay(1);
    std::flush(std::cout);
    std::cout << ".";
    delay(1);
    std::flush(std::cout);
    std::cout <<".";
    delay(1);
    clearScreen();
    std::cout << "\nYou can now move freely again!" << std::endl;
  }

}


unsigned int  Market::ItemOrSpell() {

    unsigned int choice;
    std::string Choice;

    std::cout << "*******************\n" ;
    std::cout << "Item Or Spell\n" ;
    std::cout << "1 - Item\n" ;
    std::cout << "2 - Spell\n" ;
    std::cout << "*******************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> Choice;
    std::cout << "\n\n" ;
    
    choice = atoi(Choice.c_str());

    while (Choice!="1" && Choice!="2") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> Choice;
	choice = atoi(Choice.c_str());
	
    }

    return choice;

}

bool Market::Item_Requirements(Hero *hero,Item* item) {

    int Cost = hero->getMoney() - item->getPrice();
    int Level = hero->getLevel() - item->getMinlevel();

    if (Cost>=0 && Level>=0) {
        hero->setMoney(item->getPrice());
        return 1;
    }
    else if (Cost<0 && Level>=0) {
        std::cout << "You don't have enough gold to buy this ITEM!" << std::endl;
        return 0;
    }
    else if (Cost>=0 && Level<0) {
        std::cout << "You're too inexperienced to buy this ITEM!" << std::endl;
        return 0;
    }
    else {
        std::cout << "You're too poor and too inexperienced to buy this ITEM!"  << std::endl;
        return 0;
    }


}

bool Market::Spell_Requirements(Hero *hero,Spell* spell) {

    int Cost = hero->getMoney() - spell->getPrice();
    int Level = hero->getLevel() - spell->getMinLevel();

    if (Cost>=0 && Level>=0) {
        hero->setMoney(spell->getPrice());
        return 1;
    }
    else if (Cost<0 && Level>=0) {
        std::cout << "You don't have enough gold to buy this SPELL!" << std::endl;
        return 0;
    }
    else if (Cost>=0 && Level<0) {
        std::cout << "You're too inexperienced to buy this SPELL!" << std::endl;
        return 0;
    }
    else {
        std::cout << "You're too poor and inexperienced to buy this SPELL!"  << std::endl;
        return 0;
    }


}

