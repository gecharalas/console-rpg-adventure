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


void Market::buy(Hero* hero) {


        unsigned int Choice;
        std::string choice;
        bool MeetingRequirements;

        Choice = ItemOrSpell();


        if (Choice==1) {
            std::cout << "Please enter the number of the ITEM that you want to buy!" << std::endl;
	    std::cin >> choice;

            Choice = atoi(choice.c_str());


            while (!(Choice>=1 && Choice<=30)) {

                std::cout << "Invalid input , please try again!" << std::endl;
                std::cin >> choice;
                Choice = atoi(choice.c_str());

            }

            std::vector<Item*>::iterator it = Items.begin();
            std::advance(it,Choice-1);
            MeetingRequirements = Item_Requirements(hero,*it);
            if (MeetingRequirements) {
                if (hero->getItemsInventory().size()>=4) {
                    std::cout << "Your inventory is full!" << std::endl;
                    std::cout << "You have to free some space from your inventory to buy a new item!" << std::endl;
                }
                else {
                hero->setItemsInventory(*it);
                std::cout << "Your new balance is : " << hero->getMoney() << " gold" << std::endl;
                std::cout << "Space left on your Items Inventory : " << 4-hero->getItemsInventory().size() << std::endl << std::endl;
                }
            }

        }
        else {
            std::cout << "Please enter the number of the SPELL that you want to buy!" << std::endl;
            std::cin >> choice;
            Choice = atoi(choice.c_str());
            while (!(Choice>=1 && Choice<=30)) {
                std::cout << "Invalid input , please try again!" << std::endl;
                std::cin >> choice;
                Choice = atoi(choice.c_str());
            }

            std::vector<Spell*>::iterator it = Spells.begin();
            std::advance(it,Choice-1);
            MeetingRequirements = Spell_Requirements(hero,*it);
            if (MeetingRequirements){
                if (hero->getSpellsInventory().size()>=4) {
                    std::cout << "Your inventory is full!" << std::endl;
                    std::cout << "You have to free some space from your inventory to buy a new item" << std::endl;
                }
                else {
                hero->setSpellsInventory(*it);
                std::cout << "Your new balance is : " << hero->getMoney() << " gold" << std::endl ;
                std::cout << "Space left on your Spells Inventory : " << 4-hero->getSpellsInventory().size() << std::endl << std::endl;
                }
            }

        }

}


void Market::sell(Hero *hero) {


    unsigned int Choice;
    unsigned int Number;
    std::string choice;
    choice = sellInvOrEquipped();
    if (choice=="1") {
        Choice = ItemOrSpell();


        if (Choice==1){
            if (hero->getItemsInventory().size()==0) std::cout << "Your Items Inventory is empty!" << std::endl << std::endl;
            else {
                hero->showItemsInventory();
                std::cout << "Enter the number of the ITEM  that you want to sell!" << std::endl;
                std::cin >> Number;
                while (Number > hero->getItemsInventory().size()) {
                    std::cout << "Invalid input , please try again!" << std::endl;
                    std::cin >> Number;
                }
                hero->SellItem(Number);
            }

        }
        else {
            if (hero->getSpellsInventory().size()==0) std::cout << "Your Spells Inventory is empty!" << std::endl << std::endl;
            else {
                hero->showSpellsInventory();
                std::cout << "Enter the number of the SPELL that you want to sell!" << std::endl;
                std::cin >> Number;
                while (Number > hero->getSpellsInventory().size()) {
                    std::cout << "Invalid input , please try again!" << std::endl;
                    std::cin >> Number;
                }
                hero->SellSpell(Number);
            }
        }
    }

    else  {

        sellEquipped(hero);

    }

}

std::string Market::sellInvOrEquipped() {

    std::string choice;

    std::cout << "*******************************\n" ;
    std::cout << "Sell Equipped Or Inventory Items\n";
    std::cout << "1 - Inventory\n";
    std::cout << "2 - Equipped\n";
    std::cout << "*******************************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice!="1" && choice!="2") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }
    std::cout << std::endl;

    return choice;

}

void Market::sellEquipped(Hero* hero) {
    std::string choice;

    std::cout << "*******************************\n" ;
    std::cout << "Sell Item\n";
    std::cout << "1 - Right Hand\n";
    std::cout << "2 - Left Hand\n";
    std::cout << "3 - Both Hands\n";
    std::cout << "*******************************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice!="1" && choice!="2" && choice!="3") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }
    std::cout << std::endl;

    if (choice=="1") {
        if (hero->getRightHand()==NULL) std::cout << "Your right-hand is currently un-equipped!" << std::endl;
        else if (hero->getRightHand()!=NULL) {

            if (hero->getRightHand()==hero->getLeftHand()) {
                std::cout << "You're currently using a two-handed weapon" << std::endl;
                std::cout << "Please select the 3rd option!" << std::endl;
            }
            else {

                hero->sellEquipped(choice);

            }
        }
    }
    else if (choice=="2") {

        if (hero->getLeftHand()==NULL) std::cout << "Your left-hand is currently un-equipped!" << std::endl;
        else if (hero->getLeftHand()!=NULL) {

                if (hero->getRightHand()==hero->getLeftHand()) {
                std::cout << "You're currently using a two-handed weapon" << std::endl;
                std::cout << "Please select the 3rd option!" << std::endl;
            }
            else {

                hero->sellEquipped(choice);

            }

        }
    }
    else {

        if (hero->getLeftHand()==NULL && hero->getRightHand()==NULL) std::cout << "Both of your hands are currently un-equipped!" << std::endl;
        else if ((hero->getLeftHand()!=NULL && hero->getRightHand()==NULL) || (hero->getLeftHand()==NULL && hero->getRightHand()!=NULL) ) {

            if (hero->getLeftHand()==NULL) {
                    std::cout << "Your left hand is un-equipped!" << std::endl;
                    std::cout << "Please select the 1st option!" << std::endl;

            }
            else {
                std::cout << "Your right hand is un-equipped!" << std::endl;
                std::cout << "Please select the 2nd option!" << std::endl;
            }

        }
        else if (hero->getLeftHand()!=NULL && hero->getRightHand()!=NULL) {

            hero->sellEquipped(choice);
        }


    }

}


