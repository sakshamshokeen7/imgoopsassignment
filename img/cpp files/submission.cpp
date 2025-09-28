#include "../headers/submission.h"
#include "../headers/student.h"   
using namespace std;

Submission::Submission(Student* s, string date, int sc, bool l)
    : student(s), submissionDate(date), score(sc), late(l) {}

Student* Submission::getStudent() const {
    return student;
}

string Submission::getDate() const {
    return submissionDate;
}

int Submission::getScore() const {
    return score;
}

bool Submission::isLate() const {
    return late;
}

void Submission::setScore(int sc) {
    score = sc;
}
