#include "prelab7.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    Queue q;
    q = queueInit();

    if (q.queueStruct->head == NULL)
        printf("\nInitalized");

    for (i = 0; i < 10; i++)
        enqueue(&i, q);

    // for (i = 0; q.queueStruct->head != NULL; q.queueStruct->head = q.queueStruct->head->next, i++)
    //     printf("\nIndex[%d]: %d", i, q.queueStruct->head->data);

    printf("\nError Code = %d", getQueueErrorCode(q));
    printf("\nQueue size: %d", getQueueSize(q));

    printf("\nRemoved data: %p", dequeue(q));
    printf("\nQueue size: %d", getQueueSize(q));

    for (i = 0; q.queueStruct->head != NULL; q.queueStruct->head = q.queueStruct->head->next, i++)
        printf("\nIndex[%d]: %p", i, q.queueStruct->head->data);

    freeQueue(q);

    return 0;
}