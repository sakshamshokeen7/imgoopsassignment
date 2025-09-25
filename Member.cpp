#include<iostream>
#include<string>
#include "club.h" 
using namespace std;

class Member{
    private:
    string name;
    int rollNumber;
    string password;

    public:
    Member(string n, int r, string p) {
        name = n;
        rollNumber = r;
        password = p;
    }

    void joinClub(club* c){
        c->addMember(this);
    }

    bool login(int inputRoll, string inputPwd) {
        return rollNumber == inputRoll && password == inputPwd;
    }


}
    