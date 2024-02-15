#include <stdio.h>
#include "lab7.h"

int main(int argc, char *argv[])
{
    Stack stack;
    int i = 0;
    int a, b, c, d, e, f, g;

    stack = initStack();

    switch (i)
    {

    case 0:
        pushStack(stack, &a);
        i++;

    case 1:
        pushStack(stack, &b);
        i++;

    case 2:
        pushStack(stack, &c);
        i++;
    case 3:
        pushStack(stack, &d);
        i++;

    case 4:
        pushStack(stack, &e);
        i++;

    case 5:
        pushStack(stack, &f);
        i++;
    }

    printf("\nSize of Stack: %d", getSize(stack));

    // for (i = 0; stack.info->top != NULL; i++, stack.info->top = stack.info->top->next)
    //     printf("\nIndex %d: %d", i, stack.info->top->data);

    printf("\nTop of Stack: %p", peekStack(stack));

    printf("\nStack contains %p (1 for yes 0 for no): %d", &b, stackContains(stack, &g));

    printf("\nRemoved Data: %p", popStack(stack));
    printf("\nTop of Stack: %p", peekStack(stack));

    // for (i = 0; stack.info->top != NULL; i++, stack.info->top = stack.info->top->next)
    //     printf("\nIndex %d: %d", i, stack.info->top->data);

    freeStack(stack);

    if (!stack.info->top)
        printf("\nFree succesful");

    return 0;
}