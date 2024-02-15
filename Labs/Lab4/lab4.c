/* *************************
 *   CS2050                *
 *   Lab Four              *
 *   Febuary 17th, 2023    *
 *   Skylar Perry          *
 ***************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ID;
    float weight;
    int stockCount;
    short colors;
} InventoryItem;

// for ALL function other than make array it is assumed that the passed in array was created using makeArray
void *makeArray(int arraySize, int elementSize) // makes and array and hides the size of that array behind the first element
{
    int *array = malloc(elementSize * arraySize + 1);
    if (array == NULL) // if malloc fails print that it did and return null
    {
        printf("Malloc failed\n");
        return NULL;
    }

    array[0] = arraySize; // hides array size behind the array
    array++;              // increments array so the size is hidden

    return array; // returns the created array
}

int getSize(void *array) // returns the size of the array from the hidden size value behind the passed in array
{
    int *p;
    p = array;

    return p[-1];
}

// for this function it is assumed that the passed in array was created using createArray, and it is also assumed
// that the array is initalized correctly
int countWithWeight(InventoryItem *items, float weight)
{
    int i;
    int counter = 0;
    for (i = 0; i < getSize(items); i++) // for loop that iterates through items array using getSize as a loop termination point
    {
        if (items[i].weight == weight) // increments counter if current meber of items array has the correct weight
        {
            counter++;
        }
    }

    return counter; // returns number of items with correct weight
}

void freeArray(void *array) // frees the array created using makeArray
{
    int *p;
    p = array;

    free(p - 1);
}