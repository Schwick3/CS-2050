#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    Node *next;
    void *data;
};

int makeList(Node **list)
{
    Node *p = malloc(sizeof(Node)); // creates two Node pointers and mallocs them
    Node *dummy = malloc(sizeof(Node));

    p->next = dummy;    // p->next points to the dummy node
    dummy->next = NULL; // dummy node points to NULL, making it the tail

    if (p == NULL) // if p is equal to NULL returns 1 as malloc failed
    {
        printf("\nInitalization failed");
        return 1;
    }

    *list = p; // sets the passed in list equal to the new list

    return 0;
}

int getSize(Node *list)
{
    Node *p;
    int i = 0;

    for (p = list; p->next != NULL; p = p->next) // iterates through the list
    {
        if (p->data) // if the current member actually has data (so not the dummy node) increments i to increase the size
            i++;
    }

    return i; // returns the size of the list
}

// for this function it is assumed that all non-dummy nodes have data in their data field
void *getAtIndex(Node *list, int index)
{
    Node *p;
    int i = 0;

    p = list;

    if (index < 0 || index >= getSize(p)) // checks if passed in index is invaild by checking if its less than zero or greater than the size of the list
    {
        printf("\nIndex is invalid");
        return NULL;
    }

    for (p = list; p->next != NULL; p = p->next) // iterates through the list
    {
        if (index == i) // if the passed in index is equal to i returns the data stored in that index
            return p->data;

        i++; // increments i to move to the next index
    }

    return p->data;
}

int insertAtTail(Node *list, void *data)
{
    Node *current;
    Node *tail = malloc(sizeof(Node));

    if (tail == NULL) // if malloc failed return 1
        return 1;

    current = list;         // sets a node pointer equal to the passed in list
    while (current != NULL) // iterates through the list to find the tail
    {
        current = current->next;
    }

    current->next = tail; // sets current equal to the new tail
    tail->data = data;    // sets the data of the new tail to be equal the passed in data
    tail->next = NULL;    // makes the new tail the new tail by having its next member point to NULL

    list = current; // sets list equal to current

    return 0;
}

void *removeFromHead(Node *list)
{
    Node *p;
    Node *q;
    void *data;
    p = malloc(sizeof(Node));
    q = malloc(sizeof(Node));
    p = list;

    if (p == NULL)
        return NULL;

    q->data = p->data; // sets a temporary q so that we can return the removed data

    p = p->next; // sets p to equal the node of the list past the head

    data = q->data; // sets data equal to the data that is about to be reomved

    free(q); // frees the removed data

    list = p; // sets the passed in list equal to p, effecivly getting rid of the head

    return data; // returns the deleted data
}

void freeList(Node **list)
{
    Node *current;
    Node *temp;
    current = *list;

    while (current != NULL) // iterates through the list, freeing each member as it iterates
    {
        temp = current->next; // temp pointer to store the next part of the list
        free(current);        // frees the current part of the list
        current = temp;       // moves current to the next part of the list using the temp pointer
    }

    current = NULL; // sets the current pointer equal to NULL

    *list = current; // sets list equal to current, freeing the list
}
