#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

// --- Authorclass ---
class Author {
private:
    string firstName;
    string lastName;

public:
    Author() : firstName(""), lastName("") {}

    void setName(string first, string last) {
        firstName = first;
        lastName = last;
    }

    string getName() const {
        if (firstName.empty() && lastName.empty()) return "N/A";
        return firstName + " " + lastName;
    }
};

// --- Bookclass ---
class Book {
private:
    string title;
    Author author; // keep Author as a member variable to demonstrate composition
    string isbn;
    bool available;

public:
    // member functions
    string getISBN() const { return isbn; }

    void setBookDetails(string t, string fName, string lName, string i) {
        title = t;
        author.setName(fName, lName);
        isbn = i;
        available = true;
    }

    void displayBookDetails() {
        cout << "Title: " << title 
             << " | Author: " << author.getName() 
             << " | ISBN: " << isbn 
             << " | Status: " << (available ? "Available" : "Borrowed") << endl;
    }

    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }
};

// --- Libraryclass ---
class Library {
private:
    Book books[5]; 

public:
    Library() {
        
        books[0].setBookDetails("1984", "George", "Orwell", "111");
        books[1].setBookDetails("To Kill a Mockingbird", "Harper", "Lee", "222");
        books[2].setBookDetails("The Great Gatsby", "F. Scott", "Fitzgerald", "333");
        books[3].setBookDetails("Moby Dick", "Herman", "Melville", "444");
        books[4].setBookDetails("Pride and Prejudice", "Jane", "Austen", "555");
    }


    void processBorrow(string inputISBN) {
        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                if (books[i].borrowBook()) {
                    cout << ">>> Success!" << endl;
                    books[i].displayBookDetails();
                } else {
                    cout << ">>> Already borrowed." << endl;
                }
                break;
            }
        }
        if (!found) cout << ">>> Not found." << endl;
    }
};



#endif