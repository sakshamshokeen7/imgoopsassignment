#include<iostream>
#include "../headers/Member.h"
#include "../headers/Club.h"
#include <string>
using namespace std;

Member::Member(string n, int r, string p) {
    name = n;
    rollNumber = r;
    password = p;
}

void Member::joinClub(club* c) {
    c->addMember(this);
}

bool Member::login(int inputRoll, string inputPwd) {
    return rollNumber == inputRoll && password == inputPwd;
}
