#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Hero.h"
#include "Monster.h"
#include "SpellEffects.h"
#include "Spell.h"


void delay(int);
void clearScreen();

bool playerRound(Hero*, Monster*,SpellEffects*);

void displayStats(Hero* hero,Monster* monster){

    hero->showStats();
    monster->showStats();
}

int playerChoice(){

    std::string choice;

    std::cout << "***********************" << std::endl;
    std::cout << "Choose your action:" << std::endl;
    std::cout << "1 - Attack"  << std::endl;
    std::cout << "2 - Cast a spell" << std::endl;
    std::cout << "3 - Use a potion" << std::endl;
    std::cout << "4 - Open inventory" << std::endl;
    std::cout << "5 - Display stats" << std::endl << std::endl;
    std::cout << "***********************" << std::endl  << std::endl ;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl ;

    while (choice!="1" && choice!="2" && choice!="3" && choice!="4" && choice!="5") {
        std::cout << "Invalid input , please try again !" << std::endl;
        std::cin >> choice;
    }

    if (choice == "1") return 1;  //attack
    else if (choice == "2") return 2;  //spell
    else if (choice == "3") return 3;  //use
    else if (choice == "4") return 4; //inventory
    else return 5;  //displayStats

}

bool heroAttack(Hero* hero,Monster* monster,SpellEffects* effects){ // returns true if monster dies, false if monster is still alive.

    unsigned int dodgeChance;

    //Seeing if Lighting Spell effect is active
    if (effects->getDodgeChanceReductionRounds() > 0){
        dodgeChance = monster->getDodgeChance() - ((monster->getDodgeChance() * effects->getDodgeChanceReduction()) / 100) ;
    }
    else
        dodgeChance = monster->getDodgeChance();


    // if true, then the monster dodges the attack.
    if ((rand() % 100) < dodgeChance){

        std::cout << std::endl << "The " << monster->getName() << " dodged your attack!" << std:: endl;
        return false;   // returning false, indicating that the monster is still alive!

    }

    unsigned int finalDamage;
    unsigned int defense;

    //Seeing if Fire Spell effect is active
    if(effects->getDefenseReductionRounds() > 0){
        defense = monster->getDefense() - ((monster->getDefense() * effects->getDefenseReduction() ) / 100);
    }
    else
        defense = monster->getDefense();

    //calculating the damage that is to be dealt to the monster
    finalDamage = hero->getDamage() - ( hero->getDamage() * defense / 100 );


    //reducing the monster's health
    monster->reduceHealth(finalDamage);
    std::cout << std::endl << "Nice hit! You caused " << finalDamage << " damage to the " << monster->getName() << "!" << std:: endl;


    //checking if the monster is dead, or if it still has health left
    if (monster->getHealth() > 0){
        std::cout << std::endl  << monster->getName() << "'s health: " << monster->getHealth() << "/" << monster->getMaxHealth()  << std:: endl << std:: endl;
        return false;

    }
    else{
        std::cout << std::endl << "You killed the " << monster->getName() << "!" << std:: endl << std:: endl;
        return true;  //monster died!!!!
    }

}

std::string castSpellInput(Hero* hero){

    hero->showSpellsBattle();

    std::cout << "Type the number of the spell you want to cast! (1-4)" << std::endl;
    std::cout << "Type 'cancel' to perform a different action." << std::endl;

    //Player input;
    std::string choice;
    std::cin >> choice;



    //Invalid input!
    while(choice != "cancel" && choice != "1" && choice != "2" && choice != "3" && choice != "4"){
        std::cout << std::endl << std::endl;
        std::cout << "Invalid input!Try again!" << std::endl;
        std::cin >> choice;
    }

    if(choice != "cancel"){
        //There is no spell available with the number given!
        if(hero->getSpellsInventory().size() < atoi(choice.c_str())){
            std::cout << std::endl << std::endl;
            std::cout << "The number " << atoi(choice.c_str()) << " doesn't belong to any spell!" << std::endl;
            delay(3);
            std::cout << std::endl;
            choice = castSpellInput(hero);
        }

        std::vector<Spell*> spells;

        spells = hero->getSpellsInventory();



        //Testing if the player has enough magic power to cast the spell!
        if(spells[atoi(choice.c_str())-1]->getEnergyCost() > hero->getMagicPower()){
            std::cout << std::endl << std::endl;
            std::cout << "You don't have enough magic power to cast this spell!" << std::endl;
            delay(3);
            std::cout << std::endl;
            choice = castSpellInput(hero);
        }
    }
    return choice;

}

bool castSpell(Hero* hero, Monster* monster,SpellEffects* effects){

        //Hero doesn't have any spells
        if (hero->getSpellsInventory().size() == 0){

            std::cout << "You don't have any spells! Please choose a different action!" << std::endl << std::endl;
            delay(3);
            playerRound(hero,monster,effects);

        }

        //Hero has spells
        else{

            std::string choice;
            choice = castSpellInput(hero);

            //Player decides not to cast a spell.
            if (choice == "cancel"){
                return playerRound(hero,monster,effects);

            }

            else if(choice == "1" || choice == "2" || choice == "3" || choice == "4" ){

                std::vector<Spell*> spells;

                spells = hero->getSpellsInventory();
                int number = atoi(choice.c_str())-1;



                //Reducing the hero's magic power
                hero->setMagicPower( hero->getMagicPower() - spells[number]->getEnergyCost());



                //reducing the monster's health
                monster->reduceHealth(hero->getSpellDamage(spells[number]));
                std::cout << std::endl << "You casted the " << spells[number]->getTypeOfSpell() << " spell " << spells[number]->getName() ;
                std::cout << "  and caused " << hero->getSpellDamage(spells[number]) << " damage." << std::endl;


                //Activating the spell's effect

                if(spells[number]->getTypeOfSpell() == "ice"){ //ice spell = damage reduction.

                    effects->setDamageReduction(spells[number]->getEffectPower());
                    effects->setDamageReductionRounds(spells[number]->getDuration());
                    std::cout << "You reduced the " <<  monster->getName() << "'s damage by " << spells[number]->getEffectPower() << "% for " << spells[number]->getDuration() << " rounds! " << std::endl;

                }
                else if (spells[number]->getTypeOfSpell() == "fire"){ //fire spell = defense reduction

                    effects->setDefenseReduction(spells[number]->getEffectPower());
                    effects->setDefenseReductionRounds(spells[number]->getDuration() + 1);
                    std::cout << "You reduced the " <<  monster->getName() << "'s defense by " << spells[number]->getEffectPower() << "% for " << spells[number]->getDuration() << " rounds! " << std::endl;

                }
                else {  //lighting spell = dodge chance reduction

                    effects->setDodgeChanceReduction(spells[number]->getEffectPower());
                    effects->setDodgeChanceReductionRounds(spells[number]->getDuration() + 1);
                    std::cout << "You reduced the " <<  monster->getName() << "'s dodge chance by " << spells[number]->getEffectPower() << "% for " << spells[number]->getDuration() << " rounds! " << std::endl;


                }


                //checking if the monster is dead, or if it still has health left
                if (monster->getHealth() > 0){
                    std::cout << std::endl << "" << monster->getName() << "'s health: " << monster->getHealth() << "/" << monster->getMaxHealth()  << std:: endl << std:: endl;
                    return false;

                }
                else{
                    std::cout << std::endl << "You killed the " << monster->getName() << "!" << std:: endl << std:: endl;
                    return true;  //monster died!!!!
                }

            }


        }
}


//returns false if no potions are available
bool usePotion(Hero* hero){


    std::vector<Item*>::iterator it;
    unsigned int counter=0;

    for (it=hero->getItemsInventory().begin();it!=hero->getItemsInventory().end();it++) {

        if ((*it)->getTypeOfItem()=="Potion") counter++;

    }

    if (counter==0){
        std::cout << "There are no potions in your inventory!" << std::endl;
        return false;
    }
    else{
            hero->usePotion();
        return true;
    }



}


// returns true if monster dies, false if monster is still alive.
bool playerRound(Hero* hero, Monster* monster,SpellEffects* effects){

    int action = playerChoice();
    std::string input;
    switch (action){

    case 1:     //attack

        return heroAttack(hero,monster,effects);

    case 2:     //spell


        return castSpell(hero,monster,effects);


    case 3:     //use

        if(usePotion(hero) == true) return false;
        else {
            delay(3);
            return playerRound(hero,monster,effects);
        }



    case 4:

        clearScreen();

        input = hero->EquipUnEquipMenu();

        while (input!="3") {
            if (input=="1") {
                hero->equip();
                input = hero->EquipUnEquipMenu();
            }
            else {
                hero->unequip();
                input = hero->EquipUnEquipMenu();
            }
        }

        std::cout << "Resuming fight..." ;
        std::flush(std::cout);
        delay(2);
        clearScreen();
        return playerRound(hero,monster,effects);




    case 5:     //displayStats
        displayStats(hero,monster);
        delay(4);
        playerRound(hero,monster,effects);


    }

}

// returns true if the hero dies, false if the hero is still alive.
bool monsterRound(Hero* hero, Monster* monster,SpellEffects* effects){

    // if true, then the hero dodges the attack.
    if ((rand() % 100) < hero->getDodgeChance()){

        std::cout << std::endl << "Nice move! You dodged the " << monster->getName() << "'s attack!" << std:: endl << std::endl;
        return false;   // returning false, indicating that the hero is still alive!

    }

    unsigned int finalDamage;

    //calculating the damage that is to be dealt to the hero
    finalDamage = (monster->getDamage()  * (100 - hero->getDefense())) / 100 ;


    //Seeing if Ice Spell effect is active
    if(effects->getDamageReductionRounds() > 0){
        finalDamage -= (finalDamage * effects->getDamageReduction()) / 100;
    }


    //reducing the hero's health
    hero->reduceHealth(finalDamage);
    std::cout << std::endl << "You were hit by the " << monster->getName() << "! You lost " << finalDamage << " health points!" << std:: endl;


    //checking if the hero is dead, or if he still has health left
    if (hero->getHealth() > 0){
        std::cout << std::endl << "Hero's health: " << hero->getHealth() << "/" << hero->getMaxHealth()  << std:: endl << std:: endl;
        return false;

    }
    else{
        std::cout << std::endl << "You were knocked unconscious!" << std:: endl ;
        std::cout << std::endl << "You lost " << hero->getMoney()/2 << " gold." <<std::endl;
        hero->setMoney(hero->getMoney()/2);
        std::cout << std::endl << "Be more careful next time!" << std:: endl << std:: endl;
        return true;  //hero died!!!!
    }


}

void replenishStats(Hero* hero, Monster* monster,unsigned int round){

    //Regenerating 10% health per round
     int heroRegeratedHealth = hero->getMaxHealth() * 5 / 100;
     int monsterRegeneratedHealth = monster->getMaxHealth() * 10 / 100;

     hero->setHealth(hero->getHealth() + heroRegeratedHealth);
     monster->setHealth(monster->getHealth() + monsterRegeneratedHealth);

     //Regenerating 1 magic power per round

     hero->setMagicPower(hero->getMagicPower()+1);

     std::cout << std::endl << "End of round " << round-1 << std::endl << std::endl;
     std::cout << "Regenerating health and magic power!" << std::endl << std:: endl;



}


void fight(Hero* hero, Monster* monster){

    //All the battle effects into one class
    SpellEffects* effects = new SpellEffects();
    displayStats(hero,monster);

    bool monsterDied = false; //turns true when a monster dies.
    bool heroDied = false; //turns true when the hero dies.
    unsigned int round = 1;

    while(monsterDied == false && heroDied == false){


        if(round !=1){
            replenishStats(hero,monster,round);
            delay(2);
        }

        monsterDied = playerRound(hero,monster,effects);

        delay(2);
        if (monsterDied == false){ //If the monster is still alive...
            heroDied = monsterRound(hero,monster,effects);
            delay(2);
        }

        round++;
        effects->roundPasses();

    }

    if(monsterDied == true){    //rewarding the hero with exp and gold!

        unsigned int money = (monster->getLevel() - hero->getLevel() + 1) * hero->getLevel() * ((rand() % 7) + 7) ;
        unsigned int exp = ((monster->getLevel() - hero->getLevel() + 1)  * 5 ) + ( (hero->getLevel() - 1) * ((rand() % 3) + 3) ) ;

        hero->increaseMoney(money);
        hero->increaseExp(exp);

        std::cout << "You received " << money << " gold and " << exp << " experience points." << std:: endl << std:: endl;

        //Checking if hero needs to level up
        hero->levelUp();


    }

    if(hero->getHealth() < 0){
        hero->setHealth(hero->getMaxHealth()/2);
    }

    delete effects;
    delay(2);
    std::cout  << "Transitioning back to the map..." ;
    std::flush(std::cout);
    delay(1);
    std::cout  << "   ..." ;
    std::flush(std::cout);
    delay(1);
    std::cout  << "   ..." ;
    std::flush(std::cout);
    delay(1);
    std::cout  << std::endl << std::endl << std::endl;

}
