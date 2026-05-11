#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

struct Node {
    int BookID;
    std::string title;
    std::string author;
    std::string yop;
    Node* next;
};

class linkedList {
public:
    Node* head;
    linkedList();
    ~linkedList();
    int addNewBook(int bookID, std::string title, std::string author, std::string yop);
    int deleteNode_Value(int bookid);
    int displayLinkedList();
    bool isListEmpty();
    Node searchTitle(std::string what);
};
#endif
