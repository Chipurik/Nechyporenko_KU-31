#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array-list.h"

void fillList(ArrayList* list, int length);
void printList(ArrayList *list);

int main() {

    srand(time(NULL));

    ArrayList* list = newArrayList();

    printf("Using function ADD (10 times)\n");
    fillList(list, 10);
    printList(list);
    printf("\n");

    printf("Using function INSERT (4 times)\n");
    insert(list, 5, 101);
    insert(list, 6, 102);
    insert(list, 7, 103);
    insert(list, 8, 104);
    printList(list);
    printf("\n");

    printf("Using function REMOVE (2 times)\n");
    removeItem(list, list->length - 1);
    removeItem(list, list->length - 1);
    printList(list);
    printf("\n");

    printf("Using function SET (2 times)\n");
    set(list, 0, 1000);
    set(list, 1, 1001);
    printList(list);
    printf("\n");

    printf("Using function GET (2 times)\n");
    printf("Element by index 2 is %d\n", get(list, 2));
    printf("Element by index 5 is %d\n", get(list, 5));
    printf("\n");

    printf("Using function SIZE\n");
    printf("Size is %d\n\n", size(list));

    return 0;
}

void fillList(ArrayList* list, int length) {
    int index;
    for (index = 0; index < length; index++) {
        add(list, rand() % 10);
    }
}

void printList(ArrayList* list) {
    int index;
    for (index = 0; index < list->length; index++) {
        printf("%d ", get(list, index));
    }
    printf("\n");
}
