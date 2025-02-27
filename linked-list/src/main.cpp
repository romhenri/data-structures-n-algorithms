#include "linkedlist.h"

int main() {
    LinkedList list;
    int value;

    std::cout << "=============================" << std::endl;
    std::cout << "Test 1: Check if list is empty" << std::endl;
    std::cout << "List empty? " << list.isEmpty() << std::endl;
    std::cout << "=============================" << std::endl;

    std::cout << "Test 2: Insert elements" << std::endl;
    list.insertElement(1, 10);
    list.insertElement(2, 19);
    list.insertElement(3, 30);
    list.insertElement(4, 40);
    list.printList();
    std::cout << "=============================" << std::endl;

    std::cout << "Test 3: Get list size" << std::endl;
    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "=============================" << std::endl;

    std::cout << "Test 4: Access element at position" << std::endl;
    value = list.getElement(1);
    std::cout << "Value at position 1: " << value << std::endl;
    std::cout << "=============================" << std::endl;

    std::cout << "Test 5: Modify an element" << std::endl;
    list.modifyElement(3, 35);
    list.printList();
    std::cout << "=============================" << std::endl;

    std::cout << "Test 6: Remove element" << std::endl;
    list.removeElement(4);
    list.printList();
    std::cout << "=============================" << std::endl;

    std::cout << "Test 7: Check if list is empty again" << std::endl;
    std::cout << "List empty? " << list.isEmpty() << std::endl;
    std::cout << "=============================" << std::endl;

    system("pause");
    return 0;
}
