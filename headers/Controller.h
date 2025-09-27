#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "club.h"

class club;
class Member;
class Student;
template<typename T>
class Vector;

class Controller {
    private:
        Vector<club*> clubs;
        Vector<Member*> members;
    public:
        void runCLI();
        void handleMemberActions(Member* member);
        Vector<club*>& listClubsOfStudent(Student* student);
        Vector<Member*>& listMembersOfClub(club* club);
        void displayAssignments(Student* student);
        void viewAssignmentSubmissions(club* club);
};

#endif // CONTROLLER_H