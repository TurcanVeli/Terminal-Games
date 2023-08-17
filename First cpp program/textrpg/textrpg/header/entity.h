#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
using namespace std;


class Entity{
    public:
        Entity(const string& fn, int h, int s, int d);
        ~Entity();
    
    
        void printStatus();
        inline string getFullName() const {return fullname;}
        inline int getHealth() const {return health;}
        inline int getDef()  const {return def;}
        int getStr()  const {return str;}
        int get_DamageofNormalAttack();
        void getDamage(int Damage);
        void decrement_Health(int n) {health -= n;}
        

    private:

        string fullname;
        int health;
        int str;
        int def;

};


#endif