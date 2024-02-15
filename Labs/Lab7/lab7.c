#include <stdio.h>
#include <stdlib.h>

// structs definitions these are all needed for the functions to properly work
typedef struct NodeStruct // node struct
{
    void *data;              // void pointer that is user data
    struct NodeStruct *next; // pointer to next node

} Node;

typedef struct stackInfo // stack info struct, contains info about the entire stack
{
    Node *top;    // Node pointer to the top of the stack
    Node *bottom; // Node pointer to the bottom of the stack
    int size;     // size of the stack, incremented and decremented by push and pop functions respectivly
} Info;

typedef struct // wrapper for stackInfo
{
    Info *info;
} Stack;

Stack initStack() // initalizes a stack O(1) complexity
{
    Stack stack;
    stack.info = malloc(sizeof(Info));

    stack.info->top = stack.info->bottom = NULL; // sets both top and bottom of stack to NULL
    stack.info->size = 0;                        // sets size of the stack to zero
    return stack;                                // returns the newly created stack to the user
}

int pushStack(Stack s, void *data) // pushes a new node onto the stack, O(1) complexity
{
    Node *new = malloc(sizeof(Node)); // mallocs new node pointer
    if (new == NULL)                  // if malloc failed return 1 beacuse the inserition will fail
        return 1;

    new->data = data;        // sets the new nodes data to the passed in data
    if (s.info->top == NULL) // if the stack is empty makes the new node both the top and bottom of the stack
    {
        printf("\nWorks");
        s.info->top = new; // sets top to new node
        new->next = NULL;  // sets the new nodes next pointer to null, making it the bottom of the stack
    }

    else // if the stack isnt empty simply inserts new node at head
    {
        new->next = s.info->top; // sets new nodes next pointer to the old stop of the stack
        s.info->top = new;       // changes the top of the stack to be the new node
    }

    s.info->size++; // increments size of the stack

    if (s.info->top->data != data) // if the new data isnt equal to the passed in data return 1 as insertion failed
        return 1;

    return 0;
}

void *peekStack(Stack s) // returns the data of the top of the stack, O(1) complexity
{
    return s.info->top->data;
}

int getSize(Stack s) // returns the size that is stored in stackInfo, O(1) complexity
{
    return s.info->size;
}

void *popStack(Stack s) // removes the top of the stack and returns its data, O(1) complexity
{
    if (getSize(s) == 0) // checks if the stack is empty, if it is return NULL
        return NULL;

    void *removedData = s.info->top->data; // temp void pointer to store the about to be removed data
    s.info->top = s.info->top->next;       // sets the top of the stack to the next node, removing the top

    s.info->size--; // decrements size

    return removedData; // returns the removed data
}

int stackContains(Stack s, void *data) // iterates through the stack checking if it contains the passed in data, O(n) complexity
{
    int i;
    Info tempInfo; // temporary info struct to check each index without affecting the passed in stack
    tempInfo.top = s.info->top;

    for (i = 0; i < getSize(s); i++, tempInfo.top = tempInfo.top->next) // stops when i is equal to getSize, so where the list ends
    {

        if (tempInfo.top->data == data) // if the data is equal to the current data stored in tempInfo return 1
            return 1;
    }

    return 0; // if the data isnt in the stack at all return 0
}

void freeStack(Stack s) // frees the passed in stack, O(n) complexity
{
    Node *next;                 // temp pointer to store the next part of the stack
    while (s.info->top != NULL) // iterates throgh the stack freeing each node as it goes, takes O(n) time
    {

        next = s.info->top->next; // stores next part of the stack
        free(s.info->top);        // frees the current part of the stack
        s.info->top = next;       // sets front equal to the temp pointer
    }

    free(s.info);  // frees the stackInfo
    s.info = NULL; // sets stackInfo to NULL
}
