#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Member.h"
#include "Vector.h"


class Club;
class Assignment;

class Student : public Member {
private:
    Vector<Club*> clubs;  

public:
    
    Student(int roll, std::string n, std::string pass);

    
    void joinClub(Club* c);      
    void listAllClubs() const;    

    
    void submitAssignment(Assignment* assignment, 
                          std::string submissionDate, 
                          bool lateFlag);
    void viewAssignments();
};

#endif
