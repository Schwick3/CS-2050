#include "lab11.h"
struct BST
{
    int value;  // value stored
    int size;   // size of BST
    BST *left;  // left side of BST, also valid BST
    BST *right; // right side of BST, also valid BST
};

int main(int argc, char *argv[])
{
    BST *newBST = initBST();

    insertBST(newBST, 3);
    insertBST(newBST, 7);
    insertBST(newBST, 1);

    preOrderPrintBST(newBST);
    printf("%d", getMaxBST(newBST));

    freeBST(newBST);
    return 0;
}