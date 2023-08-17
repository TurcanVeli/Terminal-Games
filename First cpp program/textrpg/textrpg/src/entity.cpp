#include "../header/entity.h"

Entity::Entity(const string& fn, int h, int s, int d): fullname(fn),health(h), str(s), def(d) {}

Entity::~Entity(){}



void Entity::getDamage(int damage){

    int* p_totalDamage {new int};
    *p_totalDamage = damage - getDef();
    cout << "Hasar = "<< *p_totalDamage << endl;

    if (*p_totalDamage <= 0){
        cout<<"Hasar vurulmadı"<<endl;
    }else{
        decrement_Health(*p_totalDamage);
    }
    delete p_totalDamage;
    p_totalDamage = { nullptr };

}


int Entity::get_DamageofNormalAttack(){
    return  rand() % getStr()+1;
}

void Entity::printStatus(){
    cout<<getFullName()<<" "<< "Durumu" << endl;
    cout<<"Can: "<< getHealth() << endl;
    cout<<"Güç: "<< getStr() << endl;
    cout<<"Defans: "<< getDef() << endl;
}