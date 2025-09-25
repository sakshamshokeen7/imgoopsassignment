#include "../headers/AssingmentReviewer.h"
#include "../headers/Assignment.h"
#include "../headers/Club.h"
#include <string>
using namespace std;

AssingmentReviewer::AssingmentReviewer(string n, int r, string p) : Member(n, r, p) {
    
}

void AssingmentReviewer::createAssignment(club* c, string title, int maxScore, string deadline){
	Assignment* a = new Assignment(title, maxScore, deadline);
    c->addAssignment(a);
    cout << "Assignment '" << title << "' created and added to club successfully.\n";
}




