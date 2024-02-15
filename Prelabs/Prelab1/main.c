#include "prelab1.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size = 5;
    int array[5] = {1, 1, 21, 4, 5};
    int min;
    int max;
    int distinct = 0;

    getInfo(array, size, &min, &max, &distinct);

    printf("Min = %d \nMax = %d \nDistinct Values = %d", min, max, distinct);

    return 0;
}