#include <stdlib.h>
#include <stdio.h>

// function that takes in a size as an argument and returns an array that can fit that size of characters
// also puts the size of the array in the -1 spot beind the array as an interger
char *strAlloc(int size)
{
    int *array;
    array = malloc(size * sizeof(char) + sizeof(int));
    if (array == NULL) // if malloc failed return NULL
        return NULL;

    array[0] = size;
    array++;

    return (char *)array;
}

// function that returns the legnth of the previously allocated array
int strLen(char *str)
{
    int length = str[-4];
    return length;
}

// copies a previously alloced array from another previously allocated array
// its assumed dest is at elast as large as source
void strCpy(char *source, char *dest)
{
    int length = strLen(source);
    int i;
    for (i = 0; i < length; i++)
    {
        dest[i] = source[i];
    }
}

// compares two strings, takes in two different strings are arguments and
// compares each charater to see if they are the same
// if a charater is found to not be the same the function returns 1, otherwise returns 0
// assumes dest and source are the same size
int strCmp(char *source, char *dest)
{
    int length = 0, i;

    for (i = 0; source[i] != '\0'; i++) // finds length of source
        length++;

    for (i = 0; i < length; i++)
    {
        if (dest[i] != source[i])
        {
            printf("\nStrings are not equal");
            return 1;
        }
    }

    printf("\nStrings are equal"); // prints that strings are equal

    return 0;
}

// frees an array previously allocated with strAlloc
void strFree(char *str)
{
    str--;
    free(str);
}
