#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void addNode(Node*& head, Node*& tail, int value);
void printList(const Node* head);
void printListReverse(const Node* tail);
void deleteList(Node*& head);
void deleteAfterValue(Node* current, Node*& tail, int target);

#endif