#ifndef OPERATING_SYSTEM_LINKED_LIST_H
#define OPERATING_SYSTEM_LINKED_LIST_H

typedef struct LinkedListNode Node;

typedef struct LinkedListNode {
    int value;
    Node* next;
} Node;

typedef struct {
    int length;
    Node* root;
} LinkedList;

LinkedList* newLinkedList();
void add(LinkedList* list, int value);
int size(LinkedList* list);
void insert(LinkedList* list, int index, int value);
void removeNode(LinkedList* list, int index);
void set(LinkedList* list, int index, int value);
int get(LinkedList* list, int index);

#endif //OPERATING_SYSTEM_LINKED_LIST_H
