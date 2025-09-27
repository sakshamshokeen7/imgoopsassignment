#ifndef MEMBER_H
#define MEMBER_H

#include <string>
class club; 

class Member {
private:
    std::string name;
    int rollNumber;
    std::string password;

public:
    Member(std::string n, int r, std::string p);

    void joinClub(club* c);
    bool login(int inputRoll, std::string inputPwd);

   
    std::string getName() const { return name; }
    int getRoll() const { return rollNumber; }
};

#endif
