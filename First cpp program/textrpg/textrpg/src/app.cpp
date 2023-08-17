#include "../header/app.h"
#include "../header/player.h"
#include "../header/enemy.h"
#include "../header/skill.h"



#include <iostream>
#include <stdlib.h>

using namespace std;
#define ENEMYCOUNT 5




void App::run(){
    cout<<"welcome, your goal is collect gold and beat npcs"<< endl;
    int number;
    cout<<"Press 1 to start. Press 0 to quit"<<endl;
    cin>> number;
    
    if (number != 1){
        cout<<"Finished"<<endl;
    }else{
        Player* player = new Player("Albert", 50,5,1);
      
        Enemy* enemyList[ENEMYCOUNT] {nullptr};
        enemyList[0] = new Enemy("Godzilla",10,2,1,rand() % 100, INSTAKILL);
        enemyList[1] = new Enemy("Borg",2,4,2, rand() % 100);
        enemyList[2] = new Enemy("Slime",1,5,3,rand() % 150, POISON);
        enemyList[3] = new Enemy("Mouse",13,3,1, rand() % 200, DOUBLEDAMAGE);
        enemyList[4] = new Enemy("Godzilla1",5,10,5, rand() % 400);

        system("cls");
        cout<<"game is starting.."<<endl;
        int npc_i = 0;
        char* select = { new char() };
        while (true){
            system("cls");
            cout<<turn<<". Turn"<<endl;
            cout<<"--------------"<<endl;
            player->printStatus();
            cout<<"--------------"<<endl;
            enemyList[npc_i]->printStatus();
            cout<<"--------------"<<endl;

            cout<<"Your Turn:"<<endl;
            cout<<"0. Normal Saldırı"<<endl;
         
            cout<<"Kullanacağın skillin baş harfini yaz(skille sahipsen gözükür? Normal saldırı için n tuşuna bas"<<endl;
            int* i = new int(1);
            if (player->getIsInstaKillSkill()) {
                cout << *i << ". " << INSTAKILL << endl;
                *i += 1;
            }
            if (player->getIsDoubleDamageSkill()) {
                cout << *i << ". " << DOUBLEDAMAGE << endl;
                *i += 1;
            }
            if (player->getIsPoisonedSkill()) {
                cout << *i << ". " << POISON << endl;
                *i += 1;
            }
            delete i;
            i = { nullptr };
            /*for (int i = 0; i < 3; i++) {
                if (*(player->getSkillArray() + i) != nullptr){
                    cout<<i+1<<". " << (*(player->getSkillArray() + 1))->getSname() << endl;//Burada hata var
                }
            }*/
            cin >> select;
            if (*select == 110){

                enemyList[npc_i]->getDamage(player->get_DamageofNormalAttack());
            }
            else if (*select == 105 && player->getIsInstaKillSkill()) {

                enemyList[npc_i]->getDamage(player->get_DamageInstaKill(enemyList[npc_i]));
            }
            else if (*select == 100 && player->getIsDoubleDamageSkill()) {
                enemyList[npc_i]->getDamage(player->get_DamageDoubleAttack());
            }
            else if (*select == 112 && player -> getIsPoisonedSkill()) {
                enemyList[npc_i]->getDamage(player->usePoison());

            }
            else {
                cout << "yanlış tuş. Normal saldırı yapılmıyor.." << endl;
            }
           
            //skilllerin counttu bittiğinde arrayden çıkar

            if(enemyList[npc_i]->get_isPoisoned()){
                enemyList[npc_i]->poisonDamage();
            }

            if (enemyList[npc_i]->getHealth() <= 0){
                player->increment_gold(enemyList[npc_i]->getGold());
                player->doActiveSkills(enemyList[npc_i]->getSkill());  
                npc_i++;
                if (npc_i == ENEMYCOUNT){
                    cout << "hepsini yendin" << endl;
                    cout << "Gold= " << player->getGold() << endl;
                    break;
                }
                cout<<"Win, sıradaki yaratık"<<endl;
                
            }

            player->getDamage(enemyList[npc_i]->get_DamageofNormalAttack());
            if (player->getHealth() < 0){
                cout<<"DEAD.."<<endl;
                break;
            }
            incerementTurn();
      
            
            
        }
        //delete[ENEMYCOUNT] enemyList;
        delete player;
        player = { nullptr };
        /* for (int i = 0; i < ENEMYCOUNT; i++)
        {
            delete enemyList[i];
        }
        */
       
        




    }


}