#include "../headers/Club.h"
#include "../headers/Member.h"
#include "../headers/Assignment.h"
#include <iostream>
using namespace std;

club::club(string name, Admin* a) {
    Clubname = name;
    admin = a;
}

void club::listallmembers() {
    cout << "members of club: " << Clubname << "\n";
    if (members.empty()) {
        cout << "NO MEMBERS\n";
        return;
    }
    for (int i = 0; i < members.getSize(); ++i) {   
        cout << "- " << members.get(i)->getName()
             << " roll no: " << members.get(i)->getRoll() << "\n";
    }
}


void club::addMember(Member* m) {
    members.push_back(m);
}

void club::addAssignment(Assignment* a) {
    assignments.push_back(a);
}

void club::removeMember(Member* m){
    for(int i=0; i<members.getSize(); i++){
        if(members.get(i) == m){
            members.erase(i);
            cout << "Member removed successfully.\n";
            return;
        }
    }
    cout << "Member not found in the club.\n";
}

void club::listallassignments() {
    cout << "Assignments in Club " << Clubname << ":\n";
    if (assignments.empty()) {
        cout << "  [No assignments]\n";
        return;
    }
    for (int i = 0; i < assignments.getSize(); i++) {
        cout << "  - " << assignments.get(i)->getTitle()
             << " (Max Score: " << assignments.get(i)->getMaxScore()
             << ", Deadline: " << assignments.get(i)->getDeadline() << ")\n";
    }
}

