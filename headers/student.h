#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Member.h"
#include "Vector.h"


class club;
class Assignment;

class Student : public Member {
private:
    Vector<club*> clubs;  

public:
    
    Student(int roll, std::string n, std::string pass);

    
    void joinClub(club* c);      
    void listAllClubs() const;    

    
    void submitAssignment(Assignment* assignment, 
                          std::string submissionDate, 
                          bool lateFlag);
    void viewAssignments();
};

#endif
