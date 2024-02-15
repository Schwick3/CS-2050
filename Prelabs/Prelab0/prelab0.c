#include <stdio.h>
#include <stdlib.h>

int getStuff(int *array, int size, int query)
{
    int i;
    int greater = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] >= query)
            greater++;
    }

    return greater;
}
