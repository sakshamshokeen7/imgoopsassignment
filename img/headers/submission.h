#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <string>

class Student;  

class Submission {
    private:
        Student* student;
        std::string submissionDate;
        int score;
        bool late;

    public:
        Submission(Student* s, std::string date, int sc, bool l);

        Student* getStudent() const;
        std::string getDate() const;
        int getScore() const;
        bool isLate() const;

        void setScore(int sc);
};

#endif
