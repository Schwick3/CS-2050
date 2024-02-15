#include "lab0.h"

/* REQUIRED CODE GOES HERE */

// function that takes a query and an array and returns the amount of
// occurances of the query in the array
countOccurrences(int size, int array[], int query)
{
    int i = 0; // declaring variables
    int occurances = 0;

    for (i = 0; i < size; i++) // for loop that iterates through the array
    {
        if (array[i] == query) // if the member of the array is equal to the qeury
            occurances++;      // adds one to occurances
    }

    return occurances; // returns the number of occurances of the query number
}