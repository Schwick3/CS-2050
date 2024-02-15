#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct
{
    int object;
    struct listStruct *next;
} List;

List *initList(int *errorCode) // simply initalizes a list, and sets it to NULL, and then returns that list to the user
{
    List *list;
    list = NULL;

    *errorCode = 0;

    return list;
}

List *insertAtHead(int object, List *node, int *errorCode)
{
    List *p;
    p = malloc(sizeof(List));
    if (p == NULL)
    {
        printf("\nShits fucked");
        *errorCode = 1;
        return node;
    }

    p->next = node;
    p->object = object;

    *errorCode = 0;

    return p;
}

int getAtIndex(int index, List *node)
{
    List *p;
    int i = 1;

    for (p = node; p->next != NULL; p = p->next)
    {
        if (index == i)
            return p->object;

        i++;
    }

    return p->object;
}

int getListLength(List *node)
{

    List *p;
    int i = 0;

    for (p = node; p->next != NULL; p = p->next)
    {

        i++;
    }

    return i;
}

List *freeList(List *node)
{
    List *current;
    List *temp;
    current = node;

    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }

    current = NULL;

    return current;
}
