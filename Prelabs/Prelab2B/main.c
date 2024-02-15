#include "prelab2b.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int minindex = 1900, maxindex = 1910;

    double *array;

    array = createDoubleArray(minindex, maxindex);
    int i;

    for (i = minindex; i <= maxindex; i++)
    {
        array[i] = i;
    }

    for (i = minindex; i <= maxindex; i++)
    {
        printf("\n%f", array[i]);
    }

    freeDoubleArray(array, minindex);

    if (array == NULL)
        printf("\nFree succesfull");

    return 0;
}