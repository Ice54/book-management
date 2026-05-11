#include "linkedList.h"
#include <iostream>
using namespace std;

linkedList::linkedList() : head(nullptr) {}

linkedList::~linkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool linkedList::isListEmpty() {
    return head == nullptr;
}

int linkedList::addNewBook(int bookID, string title, string author, string yop) {
    Node* temp = new Node;
    temp->BookID = bookID;
    temp->title = title;
    temp->author = author;
    temp->yop = yop;
    temp->next = nullptr;

    if (!head) {
        head = temp;
        return 1;
    }

    Node* current = head;
    while (current) {
        if (current->BookID == bookID) {
            delete temp;
            return -1;
        }
        current = current->next;
    }

    current = head;
    while (current->next)
        current = current->next;
    current->next = temp;
    return 1;
}

int linkedList::deleteNode_Value(int bookid) {
    if (!head) return 0;

    if (head->BookID == bookid) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return 1;
    }

    Node* current = head;
    while (current->next && current->next->BookID != bookid)
        current = current->next;

    if (!current->next) return 0;

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return 1;
}

int linkedList::displayLinkedList() {
    if (!head) {
        cout << "No books in the system.\n";
        return 0;
    }
    Node* current = head;
    int count = 1;
    while (current) {
        cout << count << ". ID: " << current->BookID << " | Title: " << current->title
             << " | Author: " << current->author << " | Year: " << current->yop << endl;
        current = current->next;
        count++;
    }
    return 1;
}

Node linkedList::searchTitle(string what) {
    Node found;
    found.BookID = -1;
    if (!head) return found;

    Node* current = head;
    while (current) {
        if (current->title == what) {
            found = *current;
            return found;
        }
        current = current->next;
    }
    return found;
}