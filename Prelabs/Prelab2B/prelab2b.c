#include <stdlib.h>
#include <stdio.h>

double *createDoubleArray(int minIndex, int maxIndex)
{
    double *array;

    array = malloc((maxIndex - minIndex + 1) * sizeof(double));
    if (array == NULL)
        printf("\nMalloc Failed");

    return array - minIndex;
}

void freeDoubleArray(double *array, int minIndex)
{
    free(array + minIndex);

    array = NULL;
}