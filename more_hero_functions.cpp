#include "Hero.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

void delay(int);
void clearScreen();

std::string Hero::WeaponOrArmor() {

    std::string choice;

    std::cout << "*******************************\n" ;
    std::cout << "Un-equip\n";
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

    return choice;
}


std::string Hero::StoreOrDrop() {

    std::string choice;

    std::cout << "*****************************************\n" ;
    std::cout << "1 - Store the item(s) in inventory\n";
    std::cout << "2 - Drop the item(s)\n";
    std::cout << "*****************************************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice!="1" && choice!="2") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }
    std::cout << std::endl;

    return choice;
}

std::string Hero::asking() {

    std::string choice;
    std::cout << "YOUR INVENTORY IS FULL!" << std::endl;
    std::cout << "*****************************************\n" ;
    std::cout << "1 - Keep the item(s)\n";
    std::cout << "2 - Drop the item(s)\n";
    std::cout << "*****************************************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice!="1" && choice!="2") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }
    std::cout << std::endl;

    return choice;
}

std::string Hero::ask_ing() {

    std::string choice;
    std::cout << "THERE IS NOT ENOUGH SPACE IN YOUR INVENTORY FOR BOTH OF THE ITEMS!" << std::endl;
    std::cout << "*****************************************\n" ;
    std::cout << "1 - Add weapon in the inventory & Keep shield\n";
    std::cout << "2 - Add weapon in the inventory & Drop shield\n";
    std::cout << "3 - Add shield in the inventory & Keep weapon\n";
    std::cout << "4 - Add shield in the inventory & Drop weapon\n";

    while (choice!="1" && choice!="2" && choice!="3" && choice!="4" ) {

        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }

    return choice;


}

std::string Hero::EquipUnEquipMenu() {


    std::string choice;

    std::cout << "*******************************\n" ;
    std::cout << "Equip-UnEquip Selection\n";
    std::cout << "1 - Equip Item\n";
    std::cout << "2 - Un-Equip Item\n";
    std::cout << "3 - Exit\n";
    std::cout << "*******************************\n\n" ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice!="1" && choice!="2" && choice!="3") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }
    std::cout << std::endl;

    return choice;


}


void Hero::SettingInvNumber() {

    unsigned int number=1;
    std::vector<Item*>::iterator it;

    for (it=ItemsInventory.begin();it!=ItemsInventory.end();it++) {
        (*it)->setNumber(number);
        number++;
    }


}


void Hero::sellEquipped(std::string choice) {

    unsigned int SellingPrice;

    if (choice=="1") { // Selling a weapon
        SellingPrice = right_hand->getPrice() / 2;
        std::cout << right_hand->getName() << " was sold for " << SellingPrice << " gold" << std::endl;
        reduceDamage(right_hand->getDamage());
        right_hand = NULL;
        money += SellingPrice;
        std::cout << "Your new balance is : " << money << " gold" << std::endl;

    }
    else if (choice=="2") { // Selling a shield
        SellingPrice = left_hand->getPrice() / 2;
        std::cout << left_hand->getName() << " was sold for " << SellingPrice << " gold" << std::endl;
        reduceProtection(left_hand->getProtection());
        left_hand = NULL;
        money += SellingPrice;
        std::cout << "Your new balance is : " << money << " gold" << std::endl;

    }
    else {
        if (right_hand->getName()==left_hand->getName()) { // Selling a two-handed weapon
            SellingPrice = right_hand->getPrice() /2 ;
            std::cout << right_hand->getName() << " was sold for " << SellingPrice << " gold" << std::endl;
            reduceDamage(right_hand->getDamage());
            right_hand = NULL;
            left_hand = NULL;
            money += SellingPrice;
            std::cout << "Your new balance is : " << money << " gold" << std::endl;

        }
        else {
            SellingPrice = (right_hand->getPrice() + left_hand->getPrice()) / 2; // Selling a one-handed weapon & a shield
            std::cout << right_hand->getName() << " was sold for " << right_hand->getPrice() / 2 << " gold" << std::endl;
            std::cout << left_hand->getName() << " was sold for " << left_hand->getPrice() / 2 << " gold" << std::endl;
            reduceDamage(right_hand->getDamage());
            reduceProtection(left_hand->getProtection());
            right_hand = NULL;
            left_hand = NULL;
            money += SellingPrice;
            std::cout << "Your new balance is : " << money << " gold" << std::endl;
        }

    }

}

Item* Hero::getRightHand() {

    return right_hand;

}

Item* Hero::getLeftHand() {

    return left_hand;

}

void Hero::setRightHand() {

    right_hand = NULL;

}

void Hero::setLeftHand() {

    left_hand = NULL;

}

void Hero::AddProtection(unsigned int prot) {

    armor += prot;
}

void Hero::AddDamage(unsigned int dmg) {

    strength += dmg;
}

void Hero::reduceDamage(unsigned int dmg) {

    strength -= dmg;
}

void Hero::reduceProtection(unsigned int prot) {

    armor -= prot;

}

void Hero::usePotion() {

    bool potions;

    potions = showPotions();

    if (potions) {

        std::string number;
        unsigned int num;
        unsigned int counter;
        bool found;
        std::vector<Item*>::iterator it;

        std::cout << "\nEnter the number of the potion that you want to use!" << std::endl;
        std::cin >> number;
        num = atoi(number.c_str());
        
        while (!(num>=1 && num<=4)) {
            std::cout << "Invalid input , please try again!" << std::endl;
            std::cin >> number;
            num = atoi(number.c_str());
            
        }
        
        found = foundPotion(num);
        
        if (found) { 
        
        	

         for (it=ItemsInventory.begin();it!=ItemsInventory.end();it++) {

            if ((*it)->getNumber()==num && (*it)->getTypeOfItem()=="Potion") {
                std::cout << "\nIts ";
                delay(1);
                std::flush(std::cout);
                std::cout << "Over ";
                delay(1);
                std::flush(std::cout);
                std::cout << "9000!!!" << std::endl;

                if ((*it)->getType()=="Health") {

                    std::cout << "\nYour HP has increased by : " << (*it)->getStats() << " points!" << std::endl;
                    healthPower += (*it)->getStats();

                }
                else if ((*it)->getType()=="Damage") {

                    std::cout << "\nYour strength has increased by : " << (*it)->getStats() << " points!" << std::endl;
                    strength += (*it)->getStats();
                }

                else if ((*it)->getType()=="Dexterity") {

                    std::cout << "\nYour dexterity has increased by : " << (*it)->getStats() << " points!" << std::endl;
                    dexterity += (*it)->getStats();
                }

                else {

                    std::cout << "\nYour agility has increased by : " << (*it)->getStats() << " points!" << std::endl;
                    agility += (*it)->getStats();

                }

                ItemsInventory.erase(it);
                if (ItemsInventory.size()!=0) SettingInvNumber();
                
                break;

            }

         }


    	}
    	else std::cout << "There is no potion with this number" << std::endl;
    	
	}
}

bool Hero::foundPotion(unsigned int number) {

    std::vector<Item*>::iterator it;
    bool found=false;
    
    for (it=ItemsInventory.begin();it!=ItemsInventory.end();it++) {

        if ((*it)->getTypeOfItem()=="Potion") {
            
            if ((*it)->getNumber()==number) {
                found=true;
                return found;
            }
        }
    }
    
    if (found==false) return found;
    
}

bool Hero::showPotions() {

    std::vector<Item*>::iterator it;
    unsigned int counter=0;
    unsigned int counter_=0;
    unsigned int StringL;

    for (it=ItemsInventory.begin();it!=ItemsInventory.end();it++) {

        if ((*it)->getTypeOfItem()=="Potion") counter_++;

    }

    for (it=ItemsInventory.begin();it!=ItemsInventory.end();it++) {
        if ((*it)->getTypeOfItem()=="Potion") {
            counter_++;

            if (counter==0) {
                std::cout << std::endl << "********************  Potions  ********************" << std::endl << std::endl;
                counter++;
            }
            std::cout << (*it)->getNumber() << "." << "  ";
            StringL = (*it)->getName().length();
            if (StringL>11) std::cout << (*it)->getName() << '\t' ;
            else std::cout << (*it)->getName() << '\t' << '\t';
            std::cout << "Type: " << (*it)->getType() << '\t';
            if ((*it)->getType()=="Health") std::cout << "HP_Bonus:   " << (*it)->getStats() << " points" << std::endl;
            else if ((*it)->getType()=="Damage") std::cout << "Dmg_Bonus:  " << (*it)->getStats() << " points" << std::endl;
            else if ((*it)->getType()=="Agility") std::cout << "Agil_Bonus: " << (*it)->getStats() << " points" << std::endl;
            else std::cout << "Dext_Bonus: " << (*it)->getStats() << " points" << std::endl;

        }

    }

    if (counter_!=0) return 1;
    else {
        std::cout << "There are no potions in your inventory!" << std::endl;
        return 0;
    }


}

std::string Hero::Menu() {

    std::string choice;

    std::cout << "******************************\n";
    std::cout << "Items-Spells Inventories\n";
    std::cout << "1 - Items Inventory\n";
    std::cout << "2 - Spells Inventory\n";
    std::cout << "3 - Exit\n";
    std::cout << "******************************\n\n";
    std::cout << "Enter your choice!" << std::endl;
    std::cin >> choice;

    while (choice != "1" && choice!= "2" && choice!= "3") {
        std::cout << "Invalid input , please try again!" << std::endl;
        std::cin >> choice;
    }

    return choice;

}
