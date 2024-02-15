#include <stdio.h>
#include "lab6.h"

int main(int argc, char *argv[])
{
    Node *list;
    int i;

    makeList(&list);

    if (list->next->next == NULL)
        printf("yes");

    for (i = 0; i < 10; i++)
    {
        insertAtTail(list, &i);
    }

    removeFromHead(list);
    printf("\nSize is: %d ", getSize(list));

    while (list->next != NULL)
    {
        printf("\n%p", list->data);
        list = list->next;
    }

    return 0;
}