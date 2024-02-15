#include "lab8.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c, d;
    PQueue Queue;
    Queue = pqInit();

    printf("Address'\n*****\nA:%p\nB:%p\nC:%p\nD:%p\n*****", &a, &b, &c, &d);

    pqInsert(&a, 15, Queue);
    pqInsert(&b, 5, Queue);
    pqInsert(&c, 2, Queue);
    pqInsert(&d, 7, Queue);

    printf("\nSize is: %d", pqGetSize(Queue));

    printf("\nPrioirty: %d", Queue.info->front->prioirty);

    printf("\nData at front: %p", pqPeek(Queue));

    pqRemoveMax(Queue);
    printf("\nPrioirty: %d", Queue.info->front->prioirty);

    pqRemoveMax(Queue);
    printf("\nPrioirty: %d", Queue.info->front->prioirty);

    pqRemoveMax(Queue);
    printf("\nPrioirty: %d", Queue.info->front->prioirty);

    printf("\nData at front: %p", pqPeek(Queue));

    printf("\nSize is: %d", pqGetSize(Queue));

    return 0;
}