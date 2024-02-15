//> A

//> March 24, 2023

/*
In this optional lab, you will cover creating and maintaining a Priority Queue ADT. You are only given a partial definition of the PQ implementation, and you must derive the remainder of the implementation from the given complexity requirements. Note that you may need to define extra helper functions or struct types to complete this lab, and that these extra definitions must go in your \textbf{lab8.c} file.

In this lab you are given the following struct definitions:

\begin{lstlisting}[language=c]
// This is a partial definition, you must complete it in your lab8.c file
typedef struct Info Info;

typedef struct {
    Info *info;
} PQueue;
\end{lstlisting}
*/

//-X1, 4

//-1, 10

//-2, 1

//-3, 2

//-4, 3

//-5, 2

//-6, 2

//-
#include <stdio.h>
#include <stdlib.h>

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

//-1
// O(1)
int pqGetErrorCode(PQueue q);

//-2
// O(1)
PQueue pqInit();

//-3
// O(n)
int pqInsert(void *data, int priority, PQueue q);

//-4
// O(1)
void *pqRemoveMax(PQueue q);

//-5
// O(1)
void *pqPeek(PQueue q);

//-6
// O(1)
int pqGetSize(PQueue q);

//-7
// O(n)
void pqFree(PQueue q);
