#include "LibrarySystem.h"
#include <iostream>

using namespace std;

int main() {
    Library lib;
    
    // 1. instantiation and validation test
    cout << "--- Step 1: Correct Initialization ---" << endl;
    Book b1;
    bool res1 = b1.setBookDetails("To Kill a Mockingbird", "Harper", "Lee", "222", "2026-01-02");
    cout << "Test 1 (Normal): " << (res1 ? "PASSED" : "FAILED") << endl;

    cout << "\n--- Step 2: Incorrect Initialization (Validation) ---" << endl;
    Book b2;
    bool res2 = b2.setBookDetails("Hamlet", "William", "Shakespeare", "ABC00", "2026-04-01");
    cout << "Test 2 (Invalid ISBN): " << (res2 ? "FAILED" : "PASSED (Rejected as expected)") << endl;

    // 2. preparing books for sorting test
    Book bookA, bookB, bookC;
    bookA.setBookDetails("The Great Gatsby", "F. Scott", "Fitzgerald", "101", "2026-01-10");
    bookB.setBookDetails("1984", "George", "Orwell", "102", "2026-02-15");
    bookC.setBookDetails("To Kill a Mockingbird", "Harper", "Lee", "222", "2026-01-02");

    // 3. testing sortBooks
    Book mixedOrder[3] = {bookB, bookC, bookA}; // 102, 222, 101 の順

    cout << "\n--- Step 3: Sorting Test (Mixed Order) ---" << endl;
    cout << "Before Sort:" << endl;
    for(int i=0; i<3; i++) mixedOrder[i].displayBookDetails();

    lib.sortBooks(mixedOrder, 3);

    cout << "\nAfter Sort (Should be 101 -> 102 -> 222):" << endl;
    for(int i=0; i<3; i++) mixedOrder[i].displayBookDetails();

    return 0;
}