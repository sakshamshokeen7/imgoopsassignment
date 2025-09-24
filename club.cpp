#include <iostream>
using namespace std;

class club{

    private:
    string Clubname;
    Admin* admin;
    Vector<Members*> members;
    Vector<Assignment*> assignments;

    public:
    club(string name,Admin*a){
        Clubname=name;
        admin=a;
    }

    void listallmembers(){
        cout<<"members of clubs:"<<Clubname<<"\n";
        if(members.empty()){
            cout<<"NO MEMBERS\n";
            return;
        }
        for(int i=0;i<members.getsize();++i){
            cout<<"-"<<members.get(i)->getName()<<"roll no:"<<members.get(i)->getRoll()<<"\n";
        }
    }
    void listallassignments(){
        cout << "Assignments in Club " << Clubname << ":\n";
        if (assignments.isEmpty()) {
            cout << "  [No assignments]\n";
            return;
        }
        for (int i = 0; i < assignments.getSize(); i++) {
            cout << "  - " << assignments.get(i)->getTitle()
                 << " (Max Score: " << assignments.get(i)->getMaxScore()
                 << ", Deadline: " << assignments.get(i)->getDeadline() << ")\n";
        }
    }

};