#include "prelab1.h"

int main(int argc, char *argv[])
{
    int array[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int query = 1;

    printf(" Amount of intergers great than %d is %d", query, getStuff(array, size, query));
}