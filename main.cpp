#include <iostream>
#include "list.h"

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // You can change these values or input from keyboard
    addNode(head, tail, 1);
    addNode(head, tail, 5);
    addNode(head, tail, 1);
    addNode(head, tail, 5);
    addNode(head, tail, 1);

    std::cout << "Initial list: ";
    printList(head);

    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;

    deleteEachAfterValue(head, tail, target);

    std::cout << "Modified list: ";
    printList(head);

    deleteList(head);
    return 0;
}
