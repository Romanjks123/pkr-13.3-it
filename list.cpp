// list.cpp
#include <iostream>
#include "list.h"

// Рекурсивно додає новий елемент в кінець списку
void addNode(Node*& head, Node*& tail, int value) {
    if (!head) {
        head = new Node{ value, nullptr, nullptr };
        tail = head;
    }
    else {
        addNode(head->next, tail, value);
        head->next->prev = head;
    }
}

// Рекурсивно виводить усі значення списку
void printList(const Node* head) {
    if (!head) {
        std::cout << std::endl;
        return;
    }
    std::cout << head->data << " ";
    printList(head->next);
}

// Рекурсивно видаляє весь список
void deleteList(Node*& head) {
    if (!head) return;
    deleteList(head->next);
    delete head;
    head = nullptr;
}

// Допоміжна функція для рекурсії
static void deleteAfterRec(Node* current, Node*& tail, int target) {
    if (!current || !current->next) return;

    if (current->data == target) {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete->next) {
            toDelete->next->prev = current;
        }
        else {
            tail = current;
        }
        delete toDelete;
        // Рухаємось далі відразу на наступний вузол
        deleteAfterRec(current->next, tail, target);
    }
    else {
        deleteAfterRec(current->next, tail, target);
    }
}

// Інтерфейсна функція — просто викликає рекурсивний обхід
void deleteEachAfterValue(Node*& head, Node*& tail, int target) {
    deleteAfterRec(head, tail, target);
}
