#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- Bookclass ---
class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    // setBookDetails
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true; 
    }

    void displayBookDetails() {
        cout << "Title: " << title << ", Author: " << author 
             << ", ISBN: " << isbn 
             << ", Status: " << (available ? "Available" : "Borrowed") << endl;
    }

    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        available = true;
    }

    string getISBN() { return isbn; }
    bool isAvailable() { return available; }
};

// --- Library class ---
class Library {
private:
    vector<Book> books; // keep track of all books in the library

public:
    // add a book to the library
    void addBook(Book book) {
        books.push_back(book);
    }

    // Find a book by ISBN and display its details
    void findBookByISBN(string isbn) {
        for (auto &book : books) {
            if (book.getISBN() == isbn) {
                book.displayBookDetails();
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // Borrowing a book by ISBN
    void borrowBookByISBN(string isbn) {
        for (auto &book : books) {
            if (book.getISBN() == isbn) {
                if (book.borrowBook()) {
                    cout << "You successfully borrowed the book!" << endl;
                } else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Error: ISBN " << isbn << " does not exist." << endl;
    }

    // all books list
    void displayAllBooks() {
        cout << "\n--- Library Collection ---" << endl;
        for (auto &book : books) {
            book.displayBookDetails();
        }
    }
};

int main() {
    Library myLibrary;

    // Add test data
    Book b1, b2, b3;
    b1.setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "101");
    b2.setBookDetails("1984", "George Orwell", "102");
    b3.setBookDetails("The Hobbit", "J.R.R. Tolkien", "103");

    myLibrary.addBook(b1);
    myLibrary.addBook(b2);
    myLibrary.addBook(b3);

    string inputIsbn;
    while (true) {
        myLibrary.displayAllBooks();
        cout << "\nEnter ISBN to borrow (0 to exit): ";
        cin >> inputIsbn;

        if (inputIsbn == "0") break;

        myLibrary.borrowBookByISBN(inputIsbn);
    }

    return 0;
}