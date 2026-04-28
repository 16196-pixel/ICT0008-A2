#include <iostream>
#include <string>
#include "LibrarySystem.h"

using namespace std;


void printArray(string label, Book books[], int n) {
    cout << label << ": ";
    for (int i = 0; i < n; i++) {
        cout << books[i].getISBN() << (i < n - 1 ? ", " : "");
    }
    cout << endl;
}

int main() {
    Library lib;

    // --- Task 1 & 2: Testing Initialization & Validation ---
    cout << "==================================================" << endl;
    cout << "Step 1 & 2: Book Validation Test (Provided Data)" << endl;
    cout << "==================================================" << endl;

    // 1. Correct Data Test
    Book b_correct;
    cout << "[Test: Correct Data - To Kill a Mockingbird]" << endl;
    if (b_correct.setBookDetails("To Kill a Mockingbird", "Harper", "Lee", "222", "2026-01-02")) {
        cout << "-> PASSED: Valid ISBN '222' accepted." << endl;
    }

    // 2. Incorrect Data Tests
    cout << "\n[Test: Incorrect Data (Validation Check)]" << endl;
    
    Book b_bad_isbn, b_bad_author, b_bad_date;
    
    // Case A: Invalid ISBN (ABC00)
    if (!b_bad_isbn.setBookDetails("Hamlet", "William", "Shakespeare", "ABC00", "2026-04-01")) {
        cout << "-> PASSED: System rejected Invalid ISBN 'ABC00'." << endl;
    } else {
        cout << "-> FAILED: System accepted alphabet in ISBN." << endl;
    }

    // Case B: Null Author 
    if (!b_bad_author.setBookDetails("The Great Gatsby", "Null", "Null", "101", "2026-01-10")) {
        cout << "-> PASSED: System rejected 'Null' author." << endl;
    }

    // Case C: Null Date
    if (!b_bad_date.setBookDetails("Moby Dick", "Herman", "Melville", "666", "Null")) {
        cout << "-> PASSED: System rejected 'Null' date." << endl;
    }

    // --- Task 3: Sorting Three Scenario Arrays ---
    cout << "\n==================================================" << endl;
    cout << "Step 3: Sorting Test (Three Scenario Arrays)" << endl;
    cout << "==================================================" << endl;

    // 正しいデータ3種を用意
    Book bookA, bookB, bookC;
    bookA.setBookDetails("To Kill a Mockingbird", "Harper", "Lee", "222", "2026-01-02");
    bookB.setBookDetails("The Great Gatsby", "F. Scott", "Fitzgerald", "101", "2026-01-10");
    bookC.setBookDetails("1984", "George", "Orwell", "102", "2026-02-15");

    // シナリオ1: Ascending order (101, 102, 222)
    Book ascBooks[3] = {bookB, bookC, bookA};
    // シナリオ2: Descending order (222, 102, 101)
    Book descBooks[3] = {bookA, bookC, bookB};
    // シナリオ3: Mixed order (102, 222, 101)
    Book mixedBooks[3] = {bookC, bookA, bookB};

    cout << "[Scenario 1: Ascending Input]" << endl;
    printArray("  Before", ascBooks, 3);
    lib.sortBooks(ascBooks, 3);
    printArray("  After ", ascBooks, 3);

    cout << "\n[Scenario 2: Descending Input]" << endl;
    printArray("  Before", descBooks, 3);
    lib.sortBooks(descBooks, 3);
    printArray("  After ", descBooks, 3);

    cout << "\n[Scenario 3: Mixed Input]" << endl;
    printArray("  Before", mixedBooks, 3);
    lib.sortBooks(mixedBooks, 3);
    printArray("  After ", mixedBooks, 3);

    return 0;
}