
#include "Assignment.h"
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

void Assignment::getSubmissions() const {
    cout << "Your Assignment Submissions:\n";
    if (submissions.isEmpty()) {
        cout << "  [No submissions]\n";
        return;
    }

    for (int i = 0; i < submissions.getSize(); i++) {
        cout << "  - " << submissions.get(i)->getTitle()
             << " (Max Score: " << submissions.get(i)->getMaxScore()
             << ", Deadline: " << submissions.get(i)->getDeadline() << ")\n";
    }
}
