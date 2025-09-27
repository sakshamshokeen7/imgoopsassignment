#include "../headers/controller.h"
#include "../headers/club.h"
#include "../headers/Member.h"
#include "../headers/student.h"
#include "../headers/vector.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

    Vector<Student*> students;
    Vector<club*> clubs;
    Member* current_user = nullptr;

//getchoice_function
int get_choice(int num_choices) {
    while (true) {
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        if (choice >= 1 && choice <= num_choices) {
            return choice;
        }
        cout << "Invalid choice! Please enter a number between 1 and " << num_choices << "." << endl;
    }
}

//find student function
Student* findStudent(int rollNumber){
    for(int i=0 ; i < students.getSize(); i++){
        if(students.get(i)->getRoll() == rollNumber){
            return students.get(i);
        }
    }
    return nullptr;
}

//find club function
club* findClub(const string& clubName){
    for(int i=0 ; i < clubs.getSize(); i++){
        if(clubs.get(i)->getName() == clubName){
            return clubs.get(i);
        }
    }
    return nullptr;
}

//display menu
void display_menu(const vector<string>& options, const string& header="Choose an option:") {
    cout << "\n" << string(header.size(), '=') << endl;
    cout << header << endl;
    cout << string(header.size(), '=') << endl;
    for (size_t i = 0; i < options.size(); ++i) {
        cout << "[" << (i+1) << "] " << options[i] << endl;
    }
    cout << endl;
}


void Controller::runCLI() {
 
        cout << "\n=== Welcome to the Club Management System ===\n";

    while (true) {
        cout << "";
        cout << "1) Create club\n";
        cout << "2) List clubs\n";
        cout << "3) Create assignment (assignment reviewer)\n";
        cout << "0) Exit\n";
        cout << "Choose an option: ";
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                string clubName;
                cout << "Enter club name: ";
                getline(cin, clubName);

                string adminName;
                cout << "Enter admin name: ";
                getline(cin, adminName);

                int adminRoll;
                cout << "Enter admin roll number: ";
                cin >> adminRoll;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string adminPwd;
                cout << "Enter admin password: ";
                getline(cin, adminPwd);

                // Simple scaffold store
                clubNames.push_back(clubName);

                // Example real object creation (uncomment and adapt to your constructors & headers):
                // Admin* admin = new Admin(adminName, adminRoll, adminPwd);
                // club* c = new club(clubName, admin);
                // clubs.push_back(c);

                cout << "Club '" << clubName << "' created (scaffold).\n";
                break;
            }

            case 2: {
                cout << "\nClubs:\n";
                if (clubNames.empty()) {
                    cout << "  (no clubs created)\n";
                } else {
                    for (size_t i = 0; i < clubNames.size(); ++i) {
                        cout << "  [" << i << "] " << clubNames[i] << "\n";
                    }
                }
                // If storing actual club* in a vector, you can list details:
                // for (size_t i = 0; i < clubs.size(); ++i) {
                //     cout << "  [" << i << "] " << clubs[i]->getName() << "\n";
                // }
                break;
            }

            case 3: {
                if (clubNames.empty()) {
                    cout << "No clubs exist. Create a club first.\n";
                    break;
                }
                int idx;
                cout << "Enter club index to add assignment to: ";
                cin >> idx;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (idx < 0 || idx >= (int)clubNames.size()) {
                    cout << "Invalid index.\n";
                    break;
                }
                string title;
                cout << "Assignment title: ";
                getline(cin, title);
                int maxScore;
                cout << "Max score: ";
                cin >> maxScore;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string deadline;
                cout << "Deadline (string): ";
                getline(cin, deadline);

                // Scaffold confirmation:
                cout << "Assignment '" << title << "' created for club '" << clubNames[idx] << "' (scaffold)\n";

                // Example real usage (uncomment & adapt if your classes are ready):
                // Assignment* a = new Assignment(title, maxScore, deadline);
                // clubs[idx]->addAssignment(a);

                break;
            }

            case 4: {
                cout << "Help:\n";
                cout << " - Use option 1 to create a club scaffold (or create real club objects by uncommenting code and ensuring constructors match).\n";
                cout << " - Option 3 shows how to create an Assignment and add to a club (requires Club::addAssignment and Assignment constructor).\n";
                break;
            }

            default:
                cout << "Unknown option.\n";
        }
    }

    cout << "Exiting CLI. Goodbye.\n";
}
// ...existing code...