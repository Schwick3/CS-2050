#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    void *data;
    Node *next;
};

int makeList(Node **list) // makes and initalizes the list, user passes in address of list pointer
{
    Node *p;
    p = malloc(sizeof(Node));

    if (p == NULL)
        printf("\nMalloc failed");

    p->next = NULL;

    *list = p;

    return 0;
}

int insertAtTail(Node **list, void *data) // intersts ndoe at tail, user passes in their list and the data they want in the node at the end
{

    Node *p;
    Node *q;
    makeList(&p);
    makeList(&q);
    q = *list;
    p = q;

    p->data = data; // sets p to be equal to the passed in data
    p->next = NULL; // sets p to null so it can be the tail

    while (q->next != NULL) // cheks to see if q->next is NULL, aka if its the tail
    {
        q = q->next; // if its not NULL moves the pointer to the next part of the list
    }

    q->next = p; // sets q->next to point to the new tail

    if (q == NULL) // if q is null then insertion failed and returns 1
        return 1;

    return 0;
}

void *removeFromHead(Node **list) // removes the head of the passsed in list
{

    Node *p;
    Node *q;
    makeList(&p);
    makeList(&q);
    p = *list;

    if (p == NULL)
        return NULL;

    q->data = p->data; // sets a temporary q so that we can return the removed data

    p = p->next; // sets p to equal the node of the list past the head

    *list = p; // sets the passed in list equal to p, effecivly getting rid of the head

    return q->data; // returns the deleted data
}

int getSize(Node *list)
{

    Node *p;
    int i = 0;

    for (p = list; p->next != NULL; p = p->next)
    {

        i++;
    }

    return i;
}

Node *freeList(Node **list)
{
    Node *p;
    Node *q;

    for (p = *list; p->next != NULL; p = p->next) // iterates through the list
    {
        q = p->next; // place holder so that the next node is remebered
        free(p);     // frees current node
        p = q;       // changes current node to be equal to placeholder
    }

    p = NULL;

    return p; // returns the freed node
}
