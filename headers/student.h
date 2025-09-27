// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include "Member.h"
#include <string>

template<typename T>
class Vector;
class club;
class Assignment;
class Submission;

class Student : public Member {
private:
    Vector<club*> clubs;
public:
    // keep parameters as (int roll, std::string n, std::string pass) but ensure we call base correctly
    Student(int roll, std::string n, std::string pass);
    void submitAssignment(Assignment* assignment, std::string submissionDate, bool lateFlag);
    void viewAssignments();
    void listAllClubs() const;
    Vector<club*>& getClubs() { return clubs; }
};

#endif // STUDENT_H
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
