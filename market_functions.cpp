#include <iostream>
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
#include "stdlib.h"



std::string Market::Market_Menu() {

    std::string choice;

    std::cout << "*****************************************\n" ;
    std::cout << "Market Menu\n";
    std::cout << "1 - Browse Weapons\n";
    std::cout << "2 - Browse Armors\n";
    std::cout << "3 - Browse Potions\n";
    std::cout << "4 - Browse Spells\n";
    std::cout << "5 - Buy Items/Spells\n";
    std::cout << "6 - Sell Items/Spells\n";
    std::cout << "7 - Exit Market\n";
    std::cout << "*****************************************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice!="1" && choice!="2" && choice!="3" && choice!="4" && choice!="5" && choice!="6" && choice!="7") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }
    std::cout << std::endl;

    return choice;

}


void Market::show_Items(unsigned int Display) {

  std::vector<Item*>::iterator it = Items.begin();
  unsigned int StringL;

    for (int i=0;i<30;i++) {

        if (i!=0) it++;

        if (i<10 && Display==1) {
            // Printing Weapons
            if (i==0) std::cout << '\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< "Weapons" << std::endl << std::endl << std::endl;
            StringL = (*it)->getName().length();
            std::cout << i+1 << "." << '\t' ;
            if (StringL>=8) {
                std::cout << (*it)->getName() << '\t' << '\t';
            }
            else std::cout << (*it)->getName() << '\t' << '\t' << '\t' ;

            std::cout << "Damage:" << (*it)->getDamage();

            if ((*it)->IsTwoHanded()==1) std::cout << '\t' << "Two-Handed" << '\t';
            else std::cout << '\t' << "One-Handed" << '\t';
            std::cout << "MinLvl required: " << (*it)->getMinlevel() << '\t' ;
            std::cout << "Price: " << (*it)->getPrice() << " gold" << std::endl ;
            if (i==9) std::cout << std::endl << std::endl;

        }
        else if (i>=10 && i<20 && Display==2) {
            // Printing Armors
            if (i==10) std::cout << std::endl << '\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< "Shields" << std::endl << std::endl << std::endl;
            StringL = (*it)->getName().length();
            std::cout << i+1 << "." << '\t' ;
            if (StringL>=16) std::cout << (*it)->getName() << '\t' ;
            else if (StringL<16) std::cout << (*it)->getName() << '\t' << '\t' ;

            std::cout << "Protection: " << (*it)->getProtection() << '\t' << '\t';
            std::cout << "MinLvl required: " << (*it)->getMinlevel() << '\t';
            std::cout << "Price: " << (*it)->getPrice() << " gold" << std::endl;
            if (i==19) std::cout << std::endl << std::endl;


        }
        else if (i>=20 && i<30 && Display==3) {
            // Printing Potions

            if (i==20) std::cout << std::endl << '\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< '\t' << "Potions" << std::endl << std::endl << std::endl;
            StringL = (*it)->getName().length();
            std::cout << i+1 << "." << '\t' ;
            std::cout << (*it)->getName() << '\t' << '\t';
            std::cout << "Type: " << (*it)->getType() << '\t' << '\t';
            if ((*it)->getType()=="Health") std::cout << "HP_Bonus:   " << (*it)->getStats() ;
            else if ((*it)->getType()=="Damage") std::cout << "Dmg_Bonus:  " << (*it)->getStats() ;
            else if ((*it)->getType()=="Agility") std::cout << "Agil_Bonus: " << (*it)->getStats();
            else std::cout << "Dext_Bonus: " << (*it)->getStats();
            std::cout << '\t' << '\t' <<"MinLvl required: " << (*it)->getMinlevel() << '\t';
            std::cout << "Price: " << (*it)->getPrice() << " gold" << std::endl;
            if (i==29) std::cout << std::endl << std::endl;

        }

    }

}

void Market::show_Spells() {

  std::vector<Spell*>::iterator it = Spells.begin();
  unsigned int StringL;

    for (int i=0;i<30;i++) {

        if (i!=0) it++;

        //Printing Spells

            if (i==0) {
                std::cout << std::endl << '\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< '\t'<< '\t' << '\t'<< "Fire Spells" << std::endl ;
                std::cout <<  '\t' <<  '\t'<<  '\t' << '\t'<< '\t' << '\t'<< "Effect:  Reduces the enemy's defense by 'EffectPower' %" << std::endl << std::endl;
            }
            if (i==10) {
                std::cout << std::endl <<'\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< '\t'<< '\t'<< '\t'<< "Lighting Spells" << std::endl ;
                std::cout <<  '\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< "Effect:  Reduces the enemy's dodge chance by 'EffectPower' %" << std::endl << std::endl;
            }
            if (i==20) {
                std::cout << std::endl <<'\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< '\t'<< '\t'<< '\t'<< "Ice Spells" << std::endl ;
                std::cout <<  '\t' <<  '\t'<<  '\t' << '\t'<< '\t'<< '\t'<< "Effect:  Reduces the enemy's damage by 'EffectPower' %" << std::endl << std::endl;
            }

            StringL = (*it)->getName().length();
            std::cout << i+1 << "." << '\t' ;

            if (StringL<=7) {
                std::cout << (*it)->getName() << '\t' << '\t';}
            else if  (StringL>7 && StringL<15) {
                std::cout << (*it)->getName() << '\t';}
            else std::cout << (*it)->getName()  ;

            std::cout << "Type: " << (*it)->getTypeOfSpell() << '\t';
            std::cout << "MinDmg:" << (*it)->getMinDamage() << '\t' << "MaxDmg: " << (*it)->getMaxDamage() << '\t';
            std::cout << "Duration: " << (*it)->getDuration() << '\t';
            std::cout << "Effect Power: " << (*it)->getEffectPower() << '\t';
            std::cout << "MinLvl: " << (*it)->getMinLevel() << '\t';
            std::cout << "Energy:" << (*it)->getEnergyCost() << '\t';
            std::cout << "Price: " << (*it)->getPrice() << std::endl;

            if (i==29) std::cout << std::endl << std::endl;

    }

}
