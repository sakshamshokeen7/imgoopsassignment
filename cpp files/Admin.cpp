#include "../headers/Admin.h"
#include "../headers/Club.h"

Admin::Admin(string n, int r, string p) : Member(n, r, p) {
	
}

void Admin::addStudent(club* club, Student* student) { 
    club->addMember(student);
}

void Admin::removeStudent(club* club, Student* student) {
    club->removeMember(student);
}
