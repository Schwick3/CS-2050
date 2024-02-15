#include "lab4.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    InventoryItem *items;
    items = makeArray(5, sizeof(InventoryItem));
    int i;
    short s;
    float weight = 5.1;

    for (i = 0; i < (getSize(items)); i++)
    {
        s = i;
        items[i].ID = i;
        items[i].weight = weight;
        items[i].stockCount = i;
        items[i].colors = s;
    }

    printf("Size is: %d\n", getSize(items));

    printf("Number of items of weight %f: %d\n", weight, countWithWeight(items, weight));

    freeArray(items);

    return 0;
}