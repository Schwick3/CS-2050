#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct // CHANGE BACK TO VOID
{
	void *data;
	struct NodeStruct *next;

} Node;

typedef struct stackInfo
{
	Node *top;
	Node *bottom;
	int size;
} Info;

typedef struct
{
	Info *info;
} Stack;
// O(1)

Stack initStack();

// O(1)

int getSize(Stack s);

// O(1)

void *peekStack(Stack s); // CHANGE BACK TO VOID

// O(1)

int pushStack(Stack s, void *data); // CHANGE BACK TO VOID

// O(1)

void *popStack(Stack s); // CHANGE BACK TO VOID

// O(n)

int stackContains(Stack s, void *data); // CHANGE BACK TO VOID

// O(n)

void freeStack(Stack s);
