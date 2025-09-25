#include<iostream>
#include<string>
using namespace std;

class Assignment{
    private:
    string title;
    int maxScore;
    string deadline;
    Vector<Submission*> submissions;

    public:
    Assignment(string t , int ms , string d){
        title = t;
        maxScore = ms;
        deadline = d;
    }
        string getTitle() const { return title; }
        int getMaxScore() const { return maxScore; }
        string getDeadline() const { return deadline; }

    void addSubmission(Submission s){
        submissions.push_back(s);
    }

    Vector<Submission*> getSubmissions(){
        
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


}