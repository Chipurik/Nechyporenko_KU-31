#include <stdlib.h>
#include <limits.h>
#include "linked-list.h"

/***********************************************PRIVATE METHODS************************************************/

int isNodeAvailableByIndex(LinkedList* list, int index) {
    return list->root != NULL && index >= 0 && index < list->length;
}

Node* getNodeByIndex(LinkedList* list, int index) {
    int i;
    Node* temp = list->root;
    for (i = 0; i <= index; i++) {
        if (i == index) {
            break;
        } else {
            temp = temp->next;
        }
    }

    return temp;
}

/************************************************PUBLIC METHODS************************************************/

LinkedList* newLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->length = 0;
    list->root = NULL;

    return list;
}

void add(LinkedList* list, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->root == NULL) {
        list->root = newNode;
    } else {
        Node* lastNode = getNodeByIndex(list, list->length - 1);
        lastNode->next = newNode;
    }

    list->length++;
}

void insert(LinkedList* list, int index, int value) {
    if (!isNodeAvailableByIndex(list, index)) {
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = list->root;
        list->root = newNode;
    } else {
        Node* parentOfNodeForInsert = getNodeByIndex(list, index - 1);
        newNode->next = parentOfNodeForInsert->next;
        parentOfNodeForInsert->next = newNode;
    }

    list->length++;
}

int size (LinkedList* list) {
    return list->length;
}

void removeNode(LinkedList* list, int index) {
    if (!isNodeAvailableByIndex(list, index)) {
        return;
    }

    Node* nodeForRemove;
    if (index == 0) {
        nodeForRemove = list->root;
        list->root = list->root->next;
    } else {
        Node* parentOfNodeForRemove = getNodeByIndex(list, index - 1);
        nodeForRemove = parentOfNodeForRemove->next;
        parentOfNodeForRemove->next = nodeForRemove->next;
    }

    free(nodeForRemove);
    list->length--;
}

void set(LinkedList* list, int index, int value) {
    if (!isNodeAvailableByIndex(list, index)) {
        return;
    }

    Node* node = getNodeByIndex(list, index);
    node->value = value;
}

int get(LinkedList* list, int index) {
    if (!isNodeAvailableByIndex(list, index)) {
        return INT_MAX;
    }

    return getNodeByIndex(list, index)->value;
}
