#include "../header/enemy.h"




Enemy::Enemy(const string& fn, int h, int s, int d, int dg, string skillTag)
:Entity(fn,h,s,d), droppedSkill_tag(skillTag), droppedGold(dg) {}

Enemy::~Enemy(){}


void Enemy::poisonDamage(){
    decrement_Health(2);
}


void Enemy::print_PoisonStatus(){
    if (get_isPoisoned()){
        cout<< "Not Poisoned.."<<endl;
    }else{
        cout<< "Poisoned..reducing 2 health every turn";
    }
}