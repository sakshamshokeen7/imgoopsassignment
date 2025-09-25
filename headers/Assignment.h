#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
using namespace std;

template <typename T>
class Vector; 
class Submission; 

class Assignment {
private:
    string title;
    int maxScore;
    string deadline;
    Vector<Submission*> submissions;

public:
    Assignment(string t, int ms, string d);
    string getTitle() const;
    int getMaxScore() const;
    string getDeadline() const;
    void addSubmission(Submission* s);
    void getSubmissions() const;
};

#endif 
