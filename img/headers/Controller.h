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
        Vector<Student*> students;
        // find a club by name within this controller's clubs vector
        club* findClub(const std::string& clubName);
        Student* findStudent(int rollNumber);
    public:
        void runCLI();
        void handleMemberActions(Member* member);
        Vector<club*>& listClubs();
        Vector<Member*>& listMembers();
        void displayAssignments(Student* student);
        void viewAssignmentSubmissions(club* club);
};

#endif // CONTROLLER_H