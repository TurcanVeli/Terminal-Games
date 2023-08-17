#include "../header/player.h"



Player::Player(const string& fn, int h, int s, int d):Entity(fn,h,s,d) {}

Player::~Player(){

}

int Player::get_DamageDoubleAttack(){
    return 2*(rand() % getStr()+1);
    
}

int Player::get_DamageInstaKill(Entity* e){
    return (e->getDef() + e->getHealth()) + 1;
}



void Player::doActiveSkills(string skillTag) {
    cout << "skilltag" << skillTag << endl;
    if (skillTag == INSTAKILL) {
        setIsInstaKillSkill();
    }
    else if (skillTag == DOUBLEDAMAGE) {
        setIsDoubleDamageSkill();
    }
    else if (skillTag == POISON) {
        setIsPoisonedSkill();
    }
    else {
        cout << "Skill Düşmedi" << endl;
    }
}


