#include <stdio.h>

// it is assumed that user will initalize and declare the array correctly for both functions
int getAverage(int array[], int size, float *result) // function that takes an array and the size of that array, and calculates average
{
    int i;
    *result = 0;
    float counter = 0;
    if (size == 0) // if size is 0 prints error message and returns 1, as you cant divide by 0, and cant increment for loop
    {
        printf("\nERROR: User input size of array as 0, please try again");
        return 1;
    }

    if (size < 0) // if size is negative prints error message and returns 1
    {
        printf("\nERROR: User input size of array as a negative number, please try again");
        return 1;
    }

    for (i = 0; i < size; i++) // for loop that adds each member of the array together
    {
        *result += array[i];
        counter++;
    }

    *result /= counter; // sum of all members of the array divied by how many members there ares

    return 0;
}

int sumEven(int array[], int size, int *result) // function that takes an array and the size of that array, and calculates sum of even parts
{
    int i;
    *result = 0;
    int evenchecker = 0;
    if (size == 0) // if size is 0 prints error message and returns 1, cant increment for loop if size is 0
    {
        printf("\nERROR: User input size of array as 0, please try again");
        return 1;
    }

    if (size < 0) // if size is negative prints error message and returns 1
    {
        printf("\nERROR: User input size of array as a negative number, please try again");
        return 1;
    }

    for (i = 0; i < size; i++) // for loop that iterates through array to make sure there are even numbers
    {
        if ((array[i] % 2) == 0)
            evenchecker++;
    }

    if (evenchecker == 0) // if there are no even numbers prints an error message
    {
        printf("\nERROR: There are no even values in array, please try again");
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        if ((array[i] % 2) == 0) // checks if current array member is even, if it is adds it to the total
            *result += array[i];
    }

    return 0;
}
