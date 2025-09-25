#ifndef CLUB_H
#define CLUB_H

#include <iostream>
#include <string>
using namespace std;

class Admin; 
class Member; 
class Assignment; 

template <typename T>
class Vector; 

class club {
    private:
        string Clubname;
        Admin* admin;
        Vector<Member*> members;
        Vector<Assignment*> assignments;

    public:
            club(string name, Admin* a) {
                Clubname = name;
                admin = a;
            }

        void listallmembers();
        void listallassignments();
        void addMember(Member* m);
        void removeMember(Member* m);
};

#endif 
