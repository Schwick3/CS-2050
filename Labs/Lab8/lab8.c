#include <stdio.h>
#include <stdlib.h>

// struct definitions, ALL of these are needed for the functions to work properly
typedef struct NodeStruct // node struct
{
    void *data;              // void pointer that is user data
    struct NodeStruct *next; // pointer to next node
    int prioirty;            // int variable that determines the priority of each node
} Node;

typedef struct queueInfo // stack info struct, contains info about the entire stack
{
    Node *front; // Node pointer to the front of the queue
    Node *rear;  // Node pointer to the rear of the queue
    int size;    // size of the queue, incremented and decremented by insert and reomve functions respectivly
    int errorCode;
} Info;

typedef struct // wrapper for stackInfo
{
    Info *info;
} PQueue;

PQueue pqInit() // function that initailizes a priority queue and then returns the initalized PQueue to the user, O(1)
{
    PQueue q;

    q.info = malloc(sizeof(Info)); // mallocs the the queueinfo part of the queue wrapper
    if (q.info == NULL)            // if malloc failed set eror code to 1
        q.info->errorCode = 1;
    else
        q.info->errorCode = 0;

    q.info->front = q.info->rear = NULL; // initalizing both front and rear to null

    q.info->size = 0; // setting queue size to zero

    return q; // returning the initalized queue
}

int pqGetErrorCode(PQueue q) // returns the error code that is stored in the PQueue struct, O(1)
{
    return q.info->errorCode;
}

int pqInsert(void *data, int priority, PQueue q) // function that finds where to put the newNode data based on its piroity and inserts it there, O(n)
{
    // printf("\nData = %d", data);
    Node *newNode;
    Node *temp = q.info->front; // node pointer than points to the front of the priority queue

    newNode = malloc(sizeof(Node)); // mallocs the newNode Node
    if (newNode == NULL)            // if malloc failed set the error code to one
        q.info->errorCode = 1;
    else
        q.info->errorCode = 0;

    newNode->data = data; // sets the data field of the newNode to be the passed in data
    newNode->prioirty = priority;
    if (q.info->front == NULL) // checks if the queue is empty
    {
        // printf("\nWorks");
        q.info->front = newNode; // sets front to newNode
        q.info->rear = newNode;  // sets rear to newNode
        newNode->next = NULL;    // makes the newNode the rear by setting its next to null
    }

    else
    {

        if (q.info->front->prioirty > newNode->prioirty) // checks to see if the first nodes priority is lower than the newNode nodes
        {
            newNode->next = q.info->front;
            q.info->front = newNode;
        }

        else // if the priority is not lower, iterate through the list and find where newNode is supposed to go in terms of priority
        {
            while (temp->next != NULL && newNode->prioirty > temp->next->prioirty) // while loop that locates the correct position for newNode
            {                                                                      // which will be after temp and before temp->next
                temp = temp->next;
            }

            newNode->next = temp->next; // puts newNode in the correct position
            temp->next = newNode;
        }
    }

    // printf("\nQueue Data = %d", q.info->rear->data);

    q.info->size++; // increments queue size

    return q.info->errorCode; // directly returns error code
}

int pqGetSize(PQueue q) // function that returns the size stored in the PQueue struct, O(1)
{
    return q.info->size;
}

void *pqRemoveMax(PQueue q) // function that remvoes the data at the front of the queue, O(1)
{
    void *removedData; // temp variable to store the removed data and next location
    Node *removedNext; // temp variable to store the part of the queue after the front

    if (pqGetSize(q) == 0) // if the queue is empty sets error code to 2 and returns NUL
    {
        q.info->errorCode = 2;
        return NULL;
    }

    // printf("\nHead data : %p", q.queueStruct->head->data);

    removedData = q.info->front->data; // sets the removed data to the data stored in the head
    removedNext = q.info->front->next; // stores next part of queue so the current front can be freed
    free(q.info->front);               // frees the front

    q.info->front = removedNext; // removes the front by setting it to the stored next value

    q.info->size--; // decrements queue size

    return removedData; // returns the removed data
}

void *pqPeek(PQueue q) // funtion that returns the data stored at the front of the queue, O(1)
{
    if (q.info->front == NULL || q.info->front->data == NULL) // checks if either the front is null or the data stored in front is null
    {
        q.info->errorCode = 1;
        return NULL;
    }

    return q.info->front->data;
}

void pqFree(PQueue q) // function that frees the passed in PQueue, O(n)
{
    Node *next;                   // temp pointer to store the next part of the queue
    while (q.info->front != NULL) // iterates throgh the queue freeing each node as it goes, takes O(n) time
    {

        next = q.info->front->next; // stores next part of the queue
        free(q.info->front);        // frees the current part of the queue
        q.info->front = next;       // sets front equal to the temp pointer
    }

    free(q.info);  // frees the queueInfo
    q.info = NULL; // sets queueInfo to NULL
}
