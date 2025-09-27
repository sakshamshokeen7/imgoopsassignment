#include "../headers/Admin.h"
#include "../headers/Club.h"
#include "../headers/Student.h"   

Admin::Admin(std::string n, int r, std::string p)
    : Member(n, r, p) {}

void Admin::addStudent(club* c, Student* student) {
    c->addMember(student);   
}

void Admin::removeStudent(club* c, Student* student) {
    c->removeMember(student);
}
