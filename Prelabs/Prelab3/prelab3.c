#include <stdlib.h>
#include <stdio.h>

int *BIGarray;

void *createArray(int size, int dataTypeSize)
{
    int *array;
    array = malloc(size * dataTypeSize);
    if (array == NULL)
        printf("\nMalloc failed");

    BIGarray = array;
    array[0] = size;
    array++;

    return array;
}

int getArraySize(void *p)
{
    int *sizeArray;
    sizeArray = p;
    return sizeArray[-1];
}
void freeArray(void *p)
{
    int *array;
    array = p;
    array--;
    if (BIGarray == array)
        printf("\nYES");

    free(array);
    array = NULL;
}
