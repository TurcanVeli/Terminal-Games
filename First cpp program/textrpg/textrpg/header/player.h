#ifndef PLAYER_H
#define PLAYER_H


#include "entity.h"
#include "skill.h"
#include <iostream>
using namespace std;

#define INSTAKILL "InstaKill"
#define DOUBLEDAMAGE "DoubleDamage"
#define POISON "Poison"

class Player: public Entity {


    public:
        Player(const string& fn, int h, int s, int d);
        ~Player();

        int get_DamageDoubleAttack();
        int get_DamageInstaKill(Entity* e);
        bool usePoison() const {return true;}
        int getGold() const {return gold;}
        bool getIsInstaKillSkill() const { return isInstaKillSkill; }
        bool getIsDoubleDamageSkill() const { return isDoubleDamageSkill; }
        bool getIsPoisonedSkill() const { return isPoisonedSkill; }
        
        void increment_gold(int n) {gold += n;}

        //BU yanlış. tekrar aynı skill düşerse tyi f yapar
        void setIsInstaKillSkill() { isInstaKillSkill = !isInstaKillSkill; }
        void setIsDoubleDamageSkill() { isDoubleDamageSkill = !isDoubleDamageSkill; }
        void setIsPoisonedSkill() { isPoisonedSkill = !isPoisonedSkill; }
        void doActiveSkills(string skillTag);
        //Skill durationu ekle sonra

    private:
        int gold = 0;
        bool isInstaKillSkill = false;
        bool isDoubleDamageSkill = false;
        bool isPoisonedSkill = false;

};






#endif