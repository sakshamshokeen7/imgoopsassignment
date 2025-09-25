#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;

class Member {
    private:
        string name;
        int rollNumber;
        string password;

    public:
        Member(string n, int r, string p);
        void joinClub(class club* c); 
        bool login(int inputRoll, string inputPwd);
};

#endif // MEMBER_H
