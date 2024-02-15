#include <stdio.h>
#include <stdlib.h>

float *readFloatFileIntoArray(FILE *fptr, int *length)
{
    int i;

    fscanf(fptr, "%d", length);
    int size = *length;

    float *array;
    array = malloc(size * sizeof(float) + sizeof(float));
    if (array == NULL)
        printf("\nMalloc failed");

    for (i = 0; i < size; i++)
    {
        fscanf(fptr, "%f", &array[i]);
    }

    return array;
}

void freeFloatArray(float **array)
{
    free(*array);
    *array = NULL;

    // if (array == NULL)
    //   printf("\nFree succesfull");
}
