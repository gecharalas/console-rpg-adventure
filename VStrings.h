#ifndef VSTRINGS_H_INCLUDED
#define VSTRINGS_H_INCLUDED
#include <string>
#include "Item.h"
#include "Spell.h"

namespace LoveIsInTheAir {

unsigned int minWeaponPrice=20;
unsigned int maxWeaponPrice=1000;
unsigned int minSpellPrice=10;
unsigned int maxSpellPrice=400;
unsigned int minLevel=1;
unsigned int maxLevel=20;
unsigned int Level;
unsigned int Dexterity;
unsigned int Agility;
unsigned int Health;
unsigned int minDamage=5;
unsigned int maxDamage=10;
unsigned int Damage;
unsigned int minSpellDamage;
unsigned int maxSpellDamage;
unsigned int minSpellDamagePerLevel = 7;
unsigned int maxSpellDamagePerLevel = 15;
unsigned int minProtection=1;
unsigned int maxProtection=3;
unsigned int Protection;
unsigned int WeaponPrice;
unsigned int SpellPrice;
unsigned int minEnergyCost=2;
unsigned int maxEnergyCost=7;
unsigned int EnergyCost;
unsigned int Display;
unsigned int Choice;
unsigned int StringL;
unsigned int numIS;
unsigned int counter=0;
unsigned int Duration;
unsigned int minDuration = 2;
unsigned int maxDuration = 4;
unsigned int DamageReduction;
unsigned int minDamageReduction = 25;
unsigned int maxDamageReduction = 40;
unsigned int DefenseReduction;
unsigned int minDefenseReduction = 25;
unsigned int maxDefenseReduction = 50;
unsigned int DodgeChanceReduction;
unsigned int minDodgeChanceReduction = 30;
unsigned int maxDodgeChanceReduction = 50;
unsigned int minAgility = 2;
unsigned int maxAgility = 10;
unsigned int minDexterity = 2;
unsigned int maxDexterity = 10;
unsigned int minHealth = 2;
unsigned int maxHealth = 10;


bool isTwoHanded;

std::string Fspellname;
std::string Lspellname;
std::string Ispellname;
std::string Wname;
std::string Aname;
std::string Pname;
std::string choice;

Item** ItemsPack;
Spell** SpellsPack;

}





#endif // VSTRINGS_H_INCLUDED
