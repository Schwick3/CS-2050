#include "lab5.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    Node *list;
    int i, d;

    makeList(&list);

    // if (list->next == NULL)
    // printf("yes");

    for (i = 0; i < 10; i++)
    {
        insertAtTail(&list, &i);
    }

    insertAtTail(&list, &d);

    removeFromHead(&list);
    printf("\nSize is: %d ", getSize(list));

    while (list->next != NULL)
    {
        printf("\n%d", *(int *)list->data);
        list = list->next;
    }

    return 0;
}