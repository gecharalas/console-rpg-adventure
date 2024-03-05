#include "SpellEffects.h"

SpellEffects::SpellEffects()
:DamageReduction(0),DamageReductionRounds(0),DefenseReduction(0),DefenseReductionRounds(0),
DodgeChanceReduction(0),DodgeChanceReductionRounds(0)
{
    //ctor
}

unsigned int SpellEffects::getDamageReduction(){

    return DamageReduction;

}

unsigned int SpellEffects::getDamageReductionRounds(){

    return DamageReductionRounds;

}

unsigned int SpellEffects::getDefenseReduction(){

    return DefenseReduction;

}

unsigned int SpellEffects::getDefenseReductionRounds(){

    return DefenseReductionRounds;

}

unsigned int SpellEffects::getDodgeChanceReduction(){

    return DodgeChanceReduction;

}

unsigned int SpellEffects::getDodgeChanceReductionRounds(){

    return DodgeChanceReductionRounds;

}

void SpellEffects::setDamageReduction(unsigned int a){

    DamageReduction = a;

}

void SpellEffects::setDamageReductionRounds(unsigned int a){

    DamageReductionRounds = a;

}

void SpellEffects::setDefenseReduction(unsigned int a){

    DefenseReduction = a;

}

void SpellEffects::setDefenseReductionRounds(unsigned int a){

    DefenseReductionRounds = a;

}

void SpellEffects::setDodgeChanceReduction(unsigned int a){

    DodgeChanceReduction = a;

}

void SpellEffects::setDodgeChanceReductionRounds(unsigned int a){

    DodgeChanceReductionRounds = a;

}

void SpellEffects::roundPasses(){

    if(DamageReductionRounds > 0)    DamageReductionRounds--;
    if(DefenseReductionRounds > 0)   DefenseReductionRounds--;
    if(DodgeChanceReductionRounds > 0)    DodgeChanceReductionRounds--;

}


