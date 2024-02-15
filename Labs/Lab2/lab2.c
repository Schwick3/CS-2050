#include <stdio.h>
#include <stdlib.h>

// for all functions it is assumed that user will pass in a valid array unless otherwise specified
// it is also assumed that size > 0 for all functions
int makeArray(int **array, int size)
{
    *array = malloc(size * sizeof(int));
    if (*array == NULL) // if malloc fails prints that it failed and return 1
    {
        printf("\nMalloc Failed");
        return 1;
    }

    return 0; // if all is good return 0
}

// initalizes each element of the passed in array to 0
void initArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

// multiplies each odd member of the array by the passed in multiplicand and then stores that value in place
int multiplyOdd(int *array, int size, int multiplicand)
{
    int i;
    int oddCounter = 0;

    for (i = 0; i < size; i++)
    {
        if ((array[i] % 2) != 0) // checks if the current member of the array is not even
        {
            array[i] *= multiplicand; // multiplies current array member by multiplicand and changes the arraymembers value to the result
            oddCounter++;             // increments the counter of odd numbers by one
        }
    }

    return oddCounter; // returns the total number of odd members of the array that got multiplied
}

// frees the passed in array
void freeArray(int **array)
{
    free(*array);
    *array = NULL;
}
