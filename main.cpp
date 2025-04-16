#include <iostream>
#include "list.h"

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Створення списку
    addNode(head, tail, 1);
    addNode(head, tail, 5);
    addNode(head, tail, 2);
    addNode(head, tail, 5);
    addNode(head, tail, 3);
    addNode(head, tail, 7);

    std::cout << "Початковий список: ";
    printList(head);

    std::cout << "Список у зворотному порядку: ";
    printListReverse(tail);

    int target;
    std::cout << "Введіть значення для видалення наступних елементів: ";
    std::cin >> target;

    deleteAfterValue(head, tail, target);

    std::cout << "Змінений список: ";
    printList(head);

    deleteList(head);
    return 0;
}