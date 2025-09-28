#include "../headers/Assignment.h"
#include <iostream>
using namespace std;

Assignment::Assignment(string t, int ms, string d) {
    title = t;
    maxScore = ms;
    deadline = d;
}

string Assignment::getTitle() const { return title; }
int Assignment::getMaxScore() const { return maxScore; }
string Assignment::getDeadline() const { return deadline; }

void Assignment::addSubmission(Submission* s) {
    submissions.push_back(s);
}

Vector<Submission*>& Assignment::getSubmissions() {
    return submissions;
}
// end Assignment implementation
