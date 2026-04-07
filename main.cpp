#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;
    }

    void displayBookDetails() {
        cout << "\nTitle: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (available ? "Available" : "Borrowed") << endl;
    }

    bool borrowBook() {
        if (available) {
            available = false;
            cout << "Book borrowed successfully." << endl;
            return true;
        } else {
            cout << "Error: Book is already borrowed." << endl;
            return false;
        }
    }

    string getISBN() {
        return isbn;
    }
};

int main() {
    Book library[5];

    library[0].setBookDetails("1984", "George Orwell", "111");
    library[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "222");
    library[2].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "333");
    library[3].setBookDetails("Moby Dick", "Herman Melville", "444");
    library[4].setBookDetails("Pride and Prejudice", "Jane Austen", "555");

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow a book (or 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program terminated." << endl;
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                library[i].displayBookDetails();
                library[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found." << endl;
        }
    }

    return 0;
}