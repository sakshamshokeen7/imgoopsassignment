#ifndef ADMIN_H
#define ADMIN_H

#include "Member.h"
#include <string>
using namespace std;

class club;   
class Student; 

class Admin : public Member {
    public:
        Admin(string n, int r, string p);

    private:
        void addStudent(club* club, Student* student);
        void removeStudent(club* club, Student* student);
    
};

#endif



