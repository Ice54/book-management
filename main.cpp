#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {
    linkedList library;
    library.addNewBook(101, "The Great Gatsby", "F. Scott Fitzgerald", "1925");
    library.addNewBook(102, "To Kill a Mockingbird", "Harper Lee", "1960");
    library.addNewBook(103, "1984", "George Orwell", "1949");
    library.addNewBook(104, "Pride and Prejudice", "Jane Austen", "1813");

    cout << "All Books:\n";
    library.displayLinkedList();

    cout << "\nSearching for '1984':\n";
    Node result = library.searchTitle("1984");
    if (result.BookID != -1)
        cout << "Found: " << result.title << " by " << result.author << " (" << result.yop << ")\n";
    else
        cout << "Not found.\n";

    cout << "\nDeleting book ID 102...\n";
    library.deleteNode_Value(102);
    library.displayLinkedList();

    return 0;
}