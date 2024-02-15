#include "prelab6.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    int index = 5;
    List *head;
    List *temp;
    int errorCode;
    // int index = 6;
    head = initList(&errorCode);

    for (i = 0; i < 100; i++)
    {
        head = insertAtHead(i, head, &errorCode);
    }

    temp = head;
    while (temp->next != NULL)
    {
        printf("\n%d", temp->object);
        temp = temp->next;
    }

    printf("\nIndex: %d = %d", index, getAtIndex(index, head));

    printf("\nSize of List = %d", getListLength(head));

    head = freeList(head);
    if (head == NULL)
        printf("\nHead is null");

    return 0;
}
