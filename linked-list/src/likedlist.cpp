#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    std::cout << "LinkedList has been deleted." << std::endl;
}

bool LinkedList::isEmpty() {
    return size == 0;
}

int LinkedList::getSize() {
    return size;
}

int LinkedList::getElement(int pos) {
    if (pos < 1 || pos > size) {
        return -1;
    }
    Node* current = head;
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

bool LinkedList::modifyElement(int pos, int value) {
    if (pos < 1 || pos > size) {
        return false;
    }
    Node* current = head;
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }
    current->data = value;
    std::cout << "Updated element at position " << pos << " to " << value << std::endl;
    return true;
}

bool LinkedList::insertElement(int pos, int value) {
    if (pos < 1 || pos > size + 1) {
        return false;
    }

    Node* new_node = new Node(value);

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* current = head;
        for (int i = 1; i < pos - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    size++;
    std::cout << "Inserted " << value << " at position " << pos << std::endl;
    return true;
}

bool LinkedList::removeElement(int pos) {
    if (pos < 1 || pos > size) {
        return false;
    }

    Node* to_delete;

    if (pos == 1) {
        to_delete = head;
        head = head->next;
    } else {
        Node* current = head;
        for (int i = 1; i < pos - 1; ++i) {
            current = current->next;
        }
        to_delete = current->next;
        current->next = to_delete->next;
    }

    std::cout << "Removed " << to_delete->data << " from position " << pos << std::endl;
    delete to_delete;
    size--;
    return true;
}

void LinkedList::printList() {
    Node* current = head;
    std::cout << "List contents: ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
