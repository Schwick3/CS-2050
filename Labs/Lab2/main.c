#include "lab2.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int *array;
    int size = 10;
    int multed;

    makeArray(&array, size);

    initArray(array, size);

    for (i = 0; i < size; i++)
    {
        printf("\nAfter Initalize: ");
        printf("Array[%d] = %d", i, array[i]);
    }

    for (i = 0; i < size; i++)
    {
        array[i] = i;
    }

    for (i = 0; i < size; i++)
    {
        printf("\nAfter Set Value: ");
        printf("Array[%d] = %d", i, array[i]);
    }

    multed = multiplyOdd(array, size, 2);

    printf("\nNumber of intergers multiplied: %d", multed);

    for (i = 0; i < size; i++)
    {
        printf("\nAfter Mult: ");
        printf("Array[%d] = %d", i, array[i]);
    }

    freeArray(&array);

    if (array == NULL)
        printf("\nFree succesfull");

    return 0;
}