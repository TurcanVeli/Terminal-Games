#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "skill.h"
#include <iostream>
using namespace std;


class Enemy: public Entity {


    public:
        Enemy(const string& fn, int h, int s, int d, int dg, string skillTag = "None");
        ~Enemy();
        //projected ile erişemiyorum, enemy->getskill olmuyor
        void setIsPoisoned(bool b) {isPoisoned = b;}
        string getSkill() const {return droppedSkill_tag;}
        int getGold() const {return droppedGold;}
        bool get_isPoisoned() const {return isPoisoned;}
        void poisonDamage();
        void print_PoisonStatus();

    private:
        //NPC öldüğünde düşecek, herzaman skill düşmek zorunda değil.
        string droppedSkill_tag;
        int droppedGold;
        bool isPoisoned = false;

};






#endif