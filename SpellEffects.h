#ifndef SPELLEFFECTS_H
#define SPELLEFFECTS_H

//All the spell effects into one class for use in the fights.
class SpellEffects
{
    public:
        SpellEffects();
        unsigned int getDamageReduction();
        unsigned int getDamageReductionRounds();

        unsigned int getDefenseReduction();
        unsigned int getDefenseReductionRounds();

        unsigned int getDodgeChanceReduction();
        unsigned int getDodgeChanceReductionRounds();

        void setDamageReduction(unsigned int);
        void setDamageReductionRounds(unsigned int);

        void setDefenseReduction(unsigned int);
        void setDefenseReductionRounds(unsigned int);

        void setDodgeChanceReduction(unsigned int);
        void setDodgeChanceReductionRounds(unsigned int);

        void roundPasses();     //Reduces the rounds till all effects expire by 1
    protected:

    private:

        unsigned int DamageReduction;           // % of damage reduction
        unsigned int DamageReductionRounds;     //Rounds till effect expires

        unsigned int DefenseReduction;          // % of defense reduction
        unsigned int DefenseReductionRounds;    //Rounds till effect expires

        unsigned int DodgeChanceReduction;          // % of dodge chance reduction
        unsigned int DodgeChanceReductionRounds;    //Rounds till effect expires




};

#endif // SPELLEFFECTS_H
