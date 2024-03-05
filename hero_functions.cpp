#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Hero.h"

void delay(int);
void clearScreen();

void Hero::equip() {
    std::vector<Item*>::iterator it = ItemsInventory.begin();
    std::string choice;
    unsigned int IntChoice;
    unsigned int IInventorySize;
    IInventorySize = ItemsInventory.size();

    if (IInventorySize==0) {
        std::cout << "ITEMS INVENTORY IS EMPTY!" << std::endl << std::endl;
        delay(3);
        clearScreen();
        return;
    }
    else {
        showItemsInventory();

        std::cout << "\nPlease enter the number of weapon/shield that you want to equip!" << std::endl;
        std::cin >> choice;

        IntChoice = atoi(choice.c_str());

	while (!(IntChoice<=ItemsInventory.size())) {

		std::cout << "Invalid input , please try again!" << std::endl;
		std::cin >> choice;
		IntChoice = atoi(choice.c_str());
	}

        std::advance(it,IntChoice-1);
        if ((*it)->getTypeOfItem()=="Weapon") {
            if ((*it)->IsTwoHanded()) { // The weapon is two-handed
                if (right_hand != NULL || left_hand != NULL){
                    std::cout << "You can't hold anymore weapons!" << std::endl;
                    choice = StoreOrDrop();
                    if (choice=="1") {
                        choice = WeaponOrArmor();
                        MovingEquippedItems(choice);

                        right_hand = *it;
                        left_hand = *it;

                        std::cout << right_hand->getName() << " is now equipped" << std::endl;

                        AddDamage(right_hand->getDamage());


                        ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                        SettingInvNumber();


                    }
                    else {
                        if (right_hand->getName()==left_hand->getName())  std::cout << "You just dropped " << right_hand->getName() << "!" << std::endl;
                        else std::cout << "You just dropped " << right_hand->getName() << " & " << left_hand->getName() << "!" << std::endl;

                        right_hand = *it;
                        left_hand = *it;

                        std::cout << right_hand->getName() << " is now equipped" << std::endl;

                        AddDamage(right_hand->getDamage());

                        ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                        SettingInvNumber();
                    }

                }
                else {
                    right_hand = *it;
                    left_hand = *it;

                    std::cout << (*it)->getName() << " is now equipped!" << std::endl;

                    AddDamage((*it)->getDamage());


                    ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                    SettingInvNumber();
                }
            }
            else {
                if (right_hand != NULL){
                    std::cout << "You can't hold anymore weapons!" << std::endl;
                    choice = StoreOrDrop();
                    if (choice=="1") {
                            choice = WeaponOrArmor();
                            MovingEquippedItems(choice);
                            right_hand = *it;

                            std::cout << right_hand->getName() << " is now equipped!" << std::endl;

                            AddDamage(right_hand->getDamage());

                            ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                            SettingInvNumber();

                    }
                    else {
                        if (right_hand->getName()==left_hand->getName()) {
                            std::cout << "You just dropped " << right_hand->getName() << "!" << std::endl;
                            left_hand = NULL;
                            reduceDamage(right_hand->getDamage());

                            right_hand = *it;
                            AddDamage(right_hand->getDamage());

                            std::cout << right_hand->getName() << " is now equipped!" << std::endl;
                            ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                            SettingInvNumber();

                        }
                        else {
                            std::cout << "You just dropped " << right_hand->getName() << "!" << std::endl;

                            right_hand = *it;

                            std::cout << right_hand->getName() << " is now equipped!" << std::endl;
                            AddDamage(right_hand->getDamage());
                            ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                            SettingInvNumber();


                        }


                    }

                }
                else {
                    right_hand = *it;

                    std::cout << right_hand->getName() << " is now equipped!" << std::endl;
                    AddDamage(right_hand->getDamage());
                    ItemsInventory.erase(it);
                    SettingInvNumber();

                }
            }

        }
        else if ((*it)->getTypeOfItem()=="Armor") {
            if (left_hand != NULL){
                if (left_hand->getTypeOfItem()=="Weapon") std::cout << "You're currently using a two-handed weapon!" << std::endl;
                else std::cout << "You can only equip one shield at a time!" << std::endl;
                    choice = StoreOrDrop();
                    if (choice=="1") {
                        choice = WeaponOrArmor();
                        MovingEquippedItems(choice);
                        left_hand = *it;
                        ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                        SettingInvNumber();
                        std::cout << left_hand->getName() << " is now equipped!" << std::endl;
                        AddProtection(left_hand->getProtection());
                    }

                    else {
                        std::cout << "You just dropped " << left_hand->getName() << "!" << std::endl;
                        left_hand = *it;
                        ItemsInventory.erase(it); // The item is now equipped and removed from the inventory
                        SettingInvNumber();
                        std::cout << left_hand->getName() << " is now equipped!" << std::endl;
                        AddProtection(left_hand->getProtection());

                    }

            }
            else {
                left_hand = *it;
                ItemsInventory.erase(it);
                SettingInvNumber();
                std::cout << left_hand->getName() << " is now equipped!" << std::endl;
                AddProtection(left_hand->getProtection());

            }
        }

        else  std::cout << "You can't equip a potion!" << std::endl;
    }

}


void Hero::unequip() {

    std::string choice;
    bool equipped;
    equipped = showEquippedItems();

    if (equipped) {


        choice = WeaponOrArmor();

        MovingEquippedItems(choice);
    }


}


void Hero::MovingEquippedItems(std::string choice) {

    unsigned int IInventorySize = ItemsInventory.size();
    std::string ask;

    if (choice=="1") {
        if (right_hand !=NULL && left_hand != NULL) {
            if (right_hand->getName()==left_hand->getName()) {
                std::cout << "You are using a two-handed weapon!" << std::endl;
                std::cout << "Select the 3rd option!" << std::endl;
                return;
            }

            else  {
                if (IInventorySize<=3) {

                        ItemsInventory.push_back(right_hand);
                        right_hand->setNumber(ItemsInventory.size());
                        std::cout << right_hand->getName() << " is now added in the inventory!" << std::endl;
                        reduceDamage(right_hand->getDamage());
                        right_hand = NULL;

                }
                else { // Inventory is full

                    ask = asking();
                    if (ask=="1") std::cout << "The item is still equipped!" << std::endl;
                    else {
                        std::cout << "You just dropped " << right_hand->getName() << "!" << std::endl;
                        reduceDamage(right_hand->getDamage());
                        right_hand = NULL;


                    }

                }
            }

        }
        else if (right_hand !=NULL && left_hand == NULL) {

                if (IInventorySize<=3) {

                        ItemsInventory.push_back(right_hand);
                        right_hand->setNumber(ItemsInventory.size());
                        std::cout << right_hand->getName() << " is now added in the inventory!" << std::endl;
                        reduceDamage(right_hand->getDamage());
                        right_hand = NULL;


                }
                else { // Inventory is full
                    ask = asking();
                    if (ask=="1") std::cout << "The item is still equipped!" << std::endl;
                    else {
                        std::cout << "You just dropped " << right_hand->getName() << "!" << std::endl;
                        reduceDamage(right_hand->getDamage());
                        right_hand = NULL;
                    }

                }
        }



    }
    else if (choice=="2") {
        if (right_hand!=NULL && left_hand!=NULL) {

            if (right_hand->getName()==left_hand->getName()) {
                std::cout << "You are using a two-handed weapon!" << std::endl;
                std::cout << "Select the 3rd option!" << std::endl;
                return;
            }

            else {
                if (IInventorySize<=3) {

                        ItemsInventory.push_back(left_hand);
                        left_hand->setNumber(ItemsInventory.size());
                        std::cout << left_hand->getName() << " is now added in the inventory!" << std::endl;
                        reduceProtection(left_hand->getProtection());
                        left_hand = NULL;

                }
                else { // Inventory is full
                    ask = asking();
                    if (ask=="1") std::cout << "The item is still equipped!" << std::endl;
                    else {
                        std::cout << "You just dropped " << left_hand->getName() << "!" << std::endl;
                        reduceProtection(left_hand->getProtection());
                        left_hand = NULL;


                    }

                }

            }

        }

        else if (left_hand!=NULL && right_hand==NULL) {
                 if (IInventorySize<=3) {

                        ItemsInventory.push_back(left_hand);
                        left_hand->setNumber(ItemsInventory.size());
                        std::cout << left_hand->getName() << " is now added in the inventory!" << std::endl;
                        reduceProtection(left_hand->getProtection());
                        left_hand = NULL;

                }
                else { // Inventory is full
                    ask = asking();
                    if (ask=="1") std::cout << "The item is still equipped!" << std::endl;
                    else {
                        std::cout << "You just dropped " << left_hand->getName() << "!" << std::endl;
                        reduceProtection(left_hand->getProtection());
                        left_hand = NULL;
                    }

                }

        }
        else if (left_hand == NULL) std::cout << "The left hand is un-equipped!" << std::endl;

    }

    else {
        if (left_hand==NULL && right_hand==NULL) std::cout << "Both of your hands are already un-equipped!" << std::endl;
        else if (left_hand == NULL && right_hand != NULL) {
            std::cout << "Only your right hand is equipped!" << std::endl;
            std::cout << "Please select the 1st option!" << std::endl;
        }
        else if (left_hand != NULL && right_hand == NULL) {
            std::cout << "Only your left hand is equipped!" << std::endl;
            std::cout << "Please select the 2nd option!" << std::endl;
        }
        else {
            if (left_hand->getName()==right_hand->getName()) { // Hero is holding a two-handed sword
                if (IInventorySize<=3) {

                    ItemsInventory.push_back(left_hand);
                    left_hand->setNumber(ItemsInventory.size());
                    std::cout << left_hand->getName() << " is now added in the inventory!" << std::endl;
                    reduceDamage(right_hand->getDamage());
                    left_hand = NULL;
                    right_hand = NULL;

                }
                else { //Inventory is full

                        ask = asking();
                        if (ask=="1") std::cout << "The item is still equipped!" << std::endl;
                        else {
                        std::cout << "You just dropped " << left_hand->getName() << "!" << std::endl;
                        reduceProtection(left_hand->getProtection());
                        left_hand = NULL;
                        }

                }

            }

            else { // hero is holding sword & shield

                if (IInventorySize<=2) {

                    ItemsInventory.push_back(left_hand);
                    ItemsInventory.push_back(right_hand);
                    left_hand->setNumber(ItemsInventory.size()-1);
                    right_hand->setNumber(ItemsInventory.size());
                    std::cout << left_hand->getName() << " is now added in the inventory!" << std::endl;
                    std::cout << right_hand->getName() << " is now added in the inventory!" << std::endl;
                    reduceDamage(right_hand->getDamage());
                    reduceProtection(left_hand->getProtection());
                    left_hand = NULL;
                    right_hand = NULL;
                }
                else if (IInventorySize==3) { //Inventory is full

                        choice = ask_ing();

                        if (choice=="1") {

                            ItemsInventory.push_back(right_hand);
                            right_hand->setNumber(ItemsInventory.size());
                            std::cout << right_hand->getName() << " is now added in the inventory!" << std::endl;
                            reduceDamage(right_hand->getDamage());
                            right_hand = NULL;

                        }
                        else if (choice=="2") {

                            ItemsInventory.push_back(right_hand);
                            right_hand->setNumber(ItemsInventory.size());
                            std::cout << right_hand->getName() << " is now added in the inventory!" << std::endl;
                            reduceDamage(right_hand->getDamage());
                            right_hand = NULL;


                            std::cout << "You just dropped " << left_hand->getName() << "!" << std::endl;
                            reduceProtection(left_hand->getProtection());
                            left_hand = NULL;
                        }
                        else if (choice=="3") {

                            ItemsInventory.push_back(left_hand);
                            left_hand->setNumber(ItemsInventory.size());
                            std::cout << left_hand->getName() << " is now added in the inventory!" << std::endl;
                            reduceProtection(left_hand->getProtection());
                            left_hand = NULL;

                        }
                        else {

                            ItemsInventory.push_back(left_hand);
                            left_hand->setNumber(ItemsInventory.size());
                            std::cout << left_hand->getName() << " is now added in the inventory!" << std::endl;
                            reduceProtection(left_hand->getProtection());
                            left_hand = NULL;

                            std::cout << "You just dropped " << right_hand->getName() << "!" << std::endl;
                            reduceDamage(right_hand->getDamage());
                            right_hand = NULL;
                        }

                }

            }

        }

    }

}




