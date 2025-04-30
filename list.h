#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void addNode(Node*& head, Node*& tail, int value);
void printList(const Node* head);
void deleteList(Node*& head);
void deleteEachAfterValue(Node*& head, Node*& tail, int target);

#endif
