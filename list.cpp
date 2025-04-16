#include <iostream>
#include "list.h"

void addNode(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList(const Node* head) {
    const Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void printListReverse(const Node* tail) {
    const Node* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteAfterValue(Node* current, Node*& tail, int target) {
    while (current && current->next) {
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
        }
        else {
            current = current->next;
        }
    }
}