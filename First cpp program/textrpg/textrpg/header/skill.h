#ifndef SKILL_H
#define SKILL_H

#include <iostream>
using namespace std;


class Skill{

    public:
        Skill(const int id,const string& snm, const string& sdc, int sd);
        int getSid() {return ID;}
        string getSname(){return Name;}
        string getSdesc(){return Desc;}
        int getSduration(){return Count;}
        bool operator==(const Skill& other) const;
    private:
        int ID;
        string Name;
        string Desc;
        int Count;
        //1. skill double attack
        //2. skill instakill
        //3. skill poison


};


#endif