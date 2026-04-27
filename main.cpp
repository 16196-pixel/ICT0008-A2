#include <iostream>
#include <string>
#include "LibrarySystem.h"

using namespace std;

int main() {
    string inputName;
    string inputId;
    string inputISBN;

    cout << "Welcome to Library System" << endl;
    cout << "Please enter your name: ";
    getline(cin, inputName);
    
    cout << "Please enter your Student ID: ";
    getline(cin, inputId);

    cout << "\n========================================" << endl;
    cout << " [SYSTEM LOG] User Authenticated" << endl;
    cout << " Name : " << inputName << endl;
    cout << " ID   : " << inputId << endl;
    cout << "========================================\n" << endl;

    Library myLibrary;

    // --- loop ---
    while (true) {
        cout << "Enter ISBN to borrow (or 0 to exit): ";
        cin >> inputISBN;
        
        if (inputISBN == "0") {
            cout << "Exiting system..." << endl;
            break;
        }

        myLibrary.processBorrow(inputISBN);
    
        cout << endl;
    }

    return 0;
}