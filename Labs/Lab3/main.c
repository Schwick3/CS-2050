#include "lab3.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *a;
    char *b;

    a = strAlloc(5);

    b = strAlloc(5);

    a = "Hello";
    b = "HeNNN";

    printf("String a length is: %d", strLen(a));

    printf("\n%s", a);
    printf("\n%s", b);

    strCmp(a, b);

    strCpy(a, b);

    printf("\n%s", a);
    printf("\n%s", b);

    strCmp(a, b);

    // strFree(a);
    // strFree(b);
    return 0;
}