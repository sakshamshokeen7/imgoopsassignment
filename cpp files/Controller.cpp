#include "../headers/controller.h"
#include "../headers/club.h"
#include "../headers/Member.h"
#include "../headers/student.h"
#include "../headers/vector.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
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
        cout << "\n--- MAIN MENU ---\n";
        vector<string> options;
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
                    students.push_back(s);
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
                for(int i=0; i<students.getSize(); i++){
                    if(students.get(i)->login(roll, to_string(password))){
                        current_user = students.get(i);
                        cout << "Login successful. Welcome, " << current_user->getName() << "!\n";
                        break;
                    } else {
                        cout << "Login failed. Please check your credentials.\n";
                    }
                }
            } else if (choice == 3) {
                cout << "Exiting the system. Goodbye!\n";
                break;
            } 
    
    // cout << "Exiting CLI. Goodbye.\n";
  } else {
    if (choice == 1) {

    }
  }
 }

}