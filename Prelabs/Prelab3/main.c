#include <stdio.h>
#include "prelab3.h"

int main(int argc, char *argv[])
{
    int i;
    int *array;
    int size = 5, dataTypeSize = 4;

    array = createArray(size, dataTypeSize);

    for (i = 0; i < size; i++)
    {
        array[i] = i;
    }

    for (i = 0; i < size; i++)
    {
        printf("\nArray[%d] = %d", i, array[i]);
    }

    printf("\nSize is: %d", getArraySize(array));

    freeArray(array);

    if (array == NULL)
        printf("\nArray is free");

    return 0;
}