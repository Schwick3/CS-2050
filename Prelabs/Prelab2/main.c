#include "prelab2.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int length = 0;
    FILE *fptr = fopen("testfile.csv", "r");
    float *array;

    array = readFloatFileIntoArray(fptr, &length);

    int i;
    for (i = 0; i < length; i++)
    {
        printf("\nArray[%d] = %f", i, array[i]);
    }

    freeFloatArray(&array);

    if (array == NULL)
        printf("\nArray freed");

    return 0;
}