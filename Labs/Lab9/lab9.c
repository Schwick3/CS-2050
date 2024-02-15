#include "lab9.h"

int binarySearch(Flight *array, Flight *query, int first, int last);

// function that dynamically allocates an array and stores the size behind it
void *makeArray(int arraySize, int elementSize)
{
    int *array;

    array = malloc(arraySize * elementSize + sizeof(int));
    if (array == NULL) // if malloc fails print that it did and return null
    {
        printf("Malloc failed\n");
        return NULL;
    }
    array[0] = arraySize;
    array++; // increments array to hide the size

    return array; // returns the dynacically allocated array
}

// function that returns the size from the passed in dynamically allocated array
int getSize(void *array)
{
    int *intArray;
    intArray = array;
    return intArray[-1];
}

// function that calls to a helper binary search function and returns the index of the flight with the passed in query
// assumes that the passed in array is sorted by flight number
// also assumes that the passed in arrays have the size stored behind them using the getSize function
int searchFlights(Flight *array, Flight *query)
{
    int last = getSize(array);
    int first = 0;
    int index;
    index = binarySearch(array, query, first, last); // uses recursive binary search helper function, and sets index equal to what it returns

    return index; // returns the index
}

// funciton that compares the distance of two flight structs to see which is greater, or if they are equal
int compareFlights(Flight *a, Flight *b)
{
    if (a->distance > b->distance) // returns 1 is a distance is greater than b distance
        return 1;
    if (a->distance < b->distance) // returns -1 if a distance is less than b distance
        return -1;

    return 0; // returns 0 if the other two if statements are not true, meaning the two distaces are equal
}

// function that frees a dyncaically allocated array
void freeArray(void *array)
{
    int *p;
    p = array;

    free(p - 1);
}

// helper binary search function that searches through the passed in Flight structs recursivly
// assumes passed in array is sorted by distance
int binarySearch(Flight *array, Flight *query, int first, int last)
{
    if (first > last) // base case that terminates the recursive loop
        return -1;    // returns 1 upon error

    int mid = (first + last) / 2; // sets middle equal to the passed in first and last divded by two

    if (query->distance > array[mid].distance)            // if the query is larger than than the middle of the passed in array, search the
        return binarySearch(array, query, mid + 1, last); //"right" larger half of the array

    else if (query->distance < array[mid].distance)        // if the query is less than the middle of the passed in array, search the
        return binarySearch(array, query, first, mid - 1); //"left" smaller half of the array

    else
        return mid; // returns mid if the query is neither greater than or less than the array being searched, meaning the query is equal to it
}
