#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    void *data;
    struct nodeStruct *next;
} Node;

typedef struct queueInfoStruct
{
    Node *head;
    Node *tail;
    int errorCode;
    int queueSize;
} QueueInfo;

typedef struct queueStruct
{
    QueueInfo *queueStruct;
} Queue;

Queue queueInit() // initalizes a queue
{
    Queue q;

    q.queueStruct = malloc(sizeof(QueueInfo)); // mallocs the the queueinfo part of the queue wrapper
    if (q.queueStruct == NULL)                 // if malloc failed set eror code to 1
        q.queueStruct->errorCode = 1;
    else
        q.queueStruct->errorCode = 0;

    q.queueStruct->head = q.queueStruct->tail = NULL; // initalizing both head and tail to null

    q.queueStruct->queueSize = 0; // setting queue size to zero

    return q; // returning the initalized queue
}

int getQueueErrorCode(Queue q) // simply returns the error code stored in the passed in queues queueInfo struct
{
    return q.queueStruct->errorCode;
}

int enqueue(void *data, Queue q) // puts the passed in data at the end of the queue
{
    // printf("\nData = %d", data);
    Node *new;
    new = malloc(sizeof(Node)); // mallocs the new Node
    if (new == NULL)            // if malloc failed set the error code to one
        q.queueStruct->errorCode = 1;
    else
        q.queueStruct->errorCode = 0;

    new->data = data;                // sets the data field of the new node to be the passed in data
    if (q.queueStruct->head == NULL) // checks if the queue is empty
    {
        printf("\nWorks");
        q.queueStruct->head = new; // sets head to new node
        q.queueStruct->tail = new; // sets tail to new node
        new->next = NULL;          // makes the new node the tail by setting its next to null
    }

    else
    {
        new->next = NULL;                // sets new nodes next to NULL in order to make it the enw tail
        q.queueStruct->tail->next = new; // sets old tails next equal to the new node
        q.queueStruct->tail = new;       // changes tail of the queue to the new node
    }
    // printf("\nQueue Data = %d", q.queueStruct->tail->data);

    q.queueStruct->queueSize++; // increments queue size

    return q.queueStruct->errorCode; // directly returns error code
}

void *dequeue(Queue q) // dont forget to change to void *
{
    void *removedData; // temp variable to store the removed data

    if (getQueueSize(q) == 0) // if the queue is empty sets error code to 2 and returns NUL
    {
        q.queueStruct->errorCode = 2;
        return NULL;
    }

    // printf("\nHead data : %p", q.queueStruct->head->data);

    removedData = q.queueStruct->head->data; // sets the removed data to the data stored in the head

    q.queueStruct->head = q.queueStruct->head->next; // removes the head by setting it to head->next

    q.queueStruct->queueSize--; // decrements queue size

    return removedData; // returns the removed data
}

int getQueueSize(Queue q) // simply returns the queue size stored within the passed in queue
{
    return q.queueStruct->queueSize;
}

void freeQueue(Queue q) // frees the stack
{
    Node *next;                         // temp pointer to store the next part of the stack
    while (q.queueStruct->head != NULL) // iterates throgh the stack freeing each node as it goes
    {
        next = q.queueStruct->head->next; // stores next part of the stack
        free(q.queueStruct->head);        // frees the current part of the stack
        q.queueStruct->head = next;       // sets top equal to the temp pointer
    }
    free(q.queueStruct);  // frees the stackInfo
    q.queueStruct = NULL; // sets stackInfo to NULL
}
