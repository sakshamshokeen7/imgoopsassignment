#include "controller.h"
#include "club.h"
#include "Member.h"
#include "student.h"
#include "Admin.h"
#include "vector.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <limits>
using namespace std;

// Controller-managed data will be used instead of globals.

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

// Find a student in this controller's students list
Student* Controller::findStudent(int rollNumber) {
    for (std::size_t i = 0; i < students.getSize(); ++i) {
        if (students.get(i)->getRoll() == rollNumber) return students.get(i);
    }
    return nullptr;
}

<<<<<<< HEAD
    //find club function
    static string normalizeName(const string& s) {
        // trim whitespace (including CR) and convert to lowercase
        size_t start = 0;
        while (start < s.size() && isspace((unsigned char)s[start])) ++start;
        size_t end = s.size();
        while (end > start && isspace((unsigned char)s[end-1])) --end;
        string t = (start < end) ? s.substr(start, end - start) : string();
        // to lower
        std::transform(t.begin(), t.end(), t.begin(), [](unsigned char c){ return std::tolower(c); });
        return t;
    }

    club* findClub(const string& clubName){
        string target = normalizeName(clubName);
        std::cout << "(debug) findClub target raw='" << clubName << "' normalized='" << target << "'" << std::endl;
        for (int i = 0; i < clubs.getSize(); i++) {
            string raw = clubs.get(i)->getName();
            string n = normalizeName(raw);
            std::cout << "(debug) comparing with club[" << i << "] raw='" << raw << "' normalized='" << n << "'" << std::endl;
            if (n == target) {
                std::cout << "(debug) match at index " << i << "\n";
                return clubs.get(i);
            }
        }
        return nullptr;
    }
=======
// The Controller::findClub method is implemented below and uses the
// Controller instance's `clubs` member.
>>>>>>> 6691c6d109488d20d649c494763df286de7ad36f


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



// Helper: find a club within this controller
club* Controller::findClub(const string& clubName) {
    for (std::size_t i = 0; i < clubs.getSize(); ++i) {
        if (clubs.get(i)->getName() == clubName) return clubs.get(i);
    }
    return nullptr;
}

void Controller::runCLI() {
 
    cout << "\n=== Welcome to the Club Management System ===\n";

    while (true) {
        cout << "\n--- MAIN MENU ---\n";
        vector<string> options;
    // `current_user` is stored as a Controller member via `members`
    // but the code uses a single active user variable. We'll store it
    // as a local static pointer so the rest of the logic works the same.
    static Member* current_user = nullptr;

    if(!current_user){
            options = {
                "Register as Member",
                "Login as Member",
                "Exit"
            };
        } else {
            options = {
                "Create a Club (Admin)",
                "Join a Club",
                "View my Clubs",
                "List all Clubs",
                // "Add Assignment (Assignment Reviewer)",
                // "View Assignments",
                // "Submit Assignment",
                "Logout",
                "Exit"
            };
        }
        display_menu(options);
        int choice = get_choice(options.size());

        if(!current_user){
            if(choice == 1){
                int roll;
                string name;
                int password;
                cout << "Enter roll number: ";
                cin >> roll;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter password: ";
                cin >> password;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                try{
                    Student* s = new Student(roll, name, to_string(password));
                    // add student to both students list and members list (for login/search)
                    students.push_back(s);
                    members.push_back(s);
                    cout << "Student registered successfully.\n";
                } catch (exception& e){
                    cout << "Error registering student. Please try again.\n";
                }

            } else if(choice == 2){
                int roll;
                int password;
                cout << "Enter roll number: ";
                cin >> roll;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter password: ";
                cin >> password;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // search registered members (students) for credentials
                bool loggedIn = false;
                for (std::size_t i = 0; i < members.getSize(); ++i) {
                    // only students are allowed to login via roll/password
                    if (Student* s = dynamic_cast<Student*>(members.get(i))) {
                        if (s->login(roll, to_string(password))) {
                            current_user = s;
                            cout << "Login successful. Welcome, " << current_user->getName() << "!\n";
                            loggedIn = true;
                            break;
                        }
                    }
                }
                if (!loggedIn) cout << "Login failed. Please check your credentials.\n";
            } else if (choice == 3) {
                cout << "Exiting the system. Goodbye!\n";
                break;
            } 
  } else {
    if (choice == 1) {
            // Allow Students to create a club and become its Admin
            if (Student* s = dynamic_cast<Student*>(current_user)) {
                string clubName;
                cout << "Enter club name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, clubName);
                if (this->findClub(clubName)) {
                    cout << "Club with this name already exists.\n";
                } else {
<<<<<<< HEAD
                        // Use the Student as the club admin (Member*)
            // create club and set admin
=======
>>>>>>> 50638ab08ecbd0d32362c224b051ec55860006a1
                        club* newClub = new club(clubName, s);
                        // push into this Controller's clubs list
                        clubs.push_back(newClub);
<<<<<<< HEAD
                        
                        // add creator to members of the club (club::addMember already avoids duplicates)
                        newClub->addMember(s);
                        // also add the club to the student's clubs list so they can view it (avoid duplicates)
                        bool studentHasClub = false;
                        for (std::size_t k = 0; k < s->getClubs().getSize(); ++k) {
                            if (s->getClubs().get(k) == newClub) { studentHasClub = true; break; }
                        }
                        if (!studentHasClub) s->getClubs().push_back(newClub);
                        // member was already pushed during registration; no-op here
=======
                        newClub->addMember(s);
                        s->getClubs().push_back(newClub);
                        members.push_back(s);
>>>>>>> 50638ab08ecbd0d32362c224b051ec55860006a1
                        cout << "Club '" << clubName << "' created successfully and " << s->getName() << " is now the admin.\n";
                }
            } else {
                cout << "Only logged-in Students can create clubs.\n";
            }
    } else if (choice == 2) {
        string clubName;
        cout << "Enter club name to join: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, clubName);
<<<<<<< HEAD
=======
<<<<<<< HEAD
        club* c = this->findClub(clubName);
=======
        // trim whitespace
        while (!clubName.empty() && isspace((unsigned char)clubName.back())) clubName.pop_back();
        size_t start = 0; while (start < clubName.size() && isspace((unsigned char)clubName[start])) start++; if (start > 0) clubName = clubName.substr(start);
>>>>>>> 6691c6d109488d20d649c494763df286de7ad36f
        club* c = findClub(clubName);
>>>>>>> 50638ab08ecbd0d32362c224b051ec55860006a1
        if (c) {
            // check if already a member
            c->addMember(current_user);
            if (Student* s = dynamic_cast<Student*>(current_user)) {
                bool already = false;
                for (std::size_t i = 0; i < s->getClubs().getSize(); ++i) {
                    if (s->getClubs().get(i) == c) { already = true; break; }
                }
                if (!already) s->getClubs().push_back(c);
            }
            cout << "Joined club '" << clubName << "' successfully." << std::endl;
        } else {
            cout << "Club not found. Available clubs:" << std::endl;
            for (int i = 0; i < clubs.getSize(); i++) cout << " - " << clubs.get(i)->getName() << std::endl;
        }
    } else if (choice == 3) {
        if (Student* s = dynamic_cast<Student*>(current_user)) {
            // Get student's clubs (assumes getClubs() returns Vector<club*>&)
            auto& myClubs = s->getClubs();
            if (myClubs.getSize() == 0) {
                cout << "You are not a member of any clubs.\n";
            } else {
                cout << "Your Clubs:\n";
                for (std::size_t i = 0; i < myClubs.getSize(); ++i) {
                    cout << "[" << (i + 1) << "] " << myClubs.get(i)->getName() << "\n";
                }

                // Prompt user to choose a club to open or 0 to go back
                int sel;
                while (true) {
                    cout << "Enter club number to open or 0 to go back: ";
                    if (!(cin >> sel)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a number.\n";
                        continue;
                    }
                    if (sel < 0 || static_cast<std::size_t>(sel) > myClubs.getSize()) {
                        cout << "Please enter a number between 0 and " << myClubs.getSize() << ".\n";
                        continue;
                    }
                    break;
                }

                if (sel == 0) {
                    // go back to main menu
                } else {
                    club* chosen = myClubs.get(sel - 1);
                    // Simple club menu
                    while (true) {
                        vector<string> clubOptions = {
                            "View Club Details",
                            "Back"
                        };
                        display_menu(clubOptions, string("Club: ") + chosen->getName());
                        int cchoice = get_choice(clubOptions.size());
                        if (cchoice == 1) {
                            cout << "Club Name: " << chosen->getName() << "\n";
                            // If club class provides more info (members, admin), show here.
                            // e.g. // cout << "Members: " << chosen->memberCount() << "\n";
                        } else if (cchoice == 2) {
                            break; // back to student's club list / main menu
                        }
                    }
                }
            }
        } else {
            cout << "Only Students can view their clubs.\n";
        }
     } else if (choice == 4) {
        if (clubs.empty()) {
            cout << "No clubs available.\n";
        } else {
            cout << "Available Clubs:\n";
            for (std::size_t i = 0; i < clubs.getSize(); ++i) {
                cout << "- " << clubs.get(i)->getName() << "\n";
            }
        }
    } else if (choice == 5) {
        cout << "Logging out " << current_user->getName() << ".\n";
        current_user = nullptr;
    } else if (choice == 6) {
        cout << "Exiting the system. Goodbye!\n";
        break;
    }
  }
 }

}