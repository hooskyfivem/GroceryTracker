#include <iostream>
#include <string>
#include "GroceryTracker.h"

using namespace std;

// This is where I display an itemized list of options a user can choose from.
void displayMenu() {
    cout << "\n=== COrner Grocer Item Tracker ===\n";
    cout << "1. Search for item frequency\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice;
    string item;

    // This is where I validate user input.
    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number 1-4.\n";
            continue;
        }

        // This is where I perform the action that the user chose. It goes through choice 1 - 4, with all of their corresponding actions.
        switch (choice) {
            case 1:
                cout << "\nEnter item name: ";
                cin >> item;
                cout << item << " was purchased " << tracker.getItemFrequency(item) << " time(s).\n";
                break;
            
            case 2:
                cout << "\nAll item frequencies:\n";
                tracker.printAllFrequencies();
                break;

            case 3:
                cout << "\nItem frequency histogram:\n";
                tracker.printHistogram();
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;
            
            default:
                cout << "Invalid option. Please select 1-4.\n";
        }

    }
    return 0;
}

