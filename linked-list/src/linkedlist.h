#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty();
    int getSize();
    int getElement(int pos);
    bool modifyElement(int pos, int value);
    bool insertElement(int pos, int value);
    bool removeElement(int pos);
    void printList();
};

#endif // LINKEDLIST_H
