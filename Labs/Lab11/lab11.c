#include "lab11.h"

struct BST
{
    int value;  // value stored
    int size;   // size of BST
    BST *left;  // left side of BST, also valid BST
    BST *right; // right side of BST, also valid BST
};

BST *initBST()
{
    BST *newBST;
    newBST = malloc(sizeof(BST));
    if (!newBST) // if BST is NULL returns NULL
        return NULL;

    newBST->left = NULL;  // sets left side of BST to be NULL
    newBST->right = NULL; // sets right side of BST to be NULL
    newBST->size = 0;     // sets the size of the BST to be NULL

    return newBST; // returns the newly created BST
}

int insertBST(BST *tree, int data) // this function takes data and inserts it into the binary tree, it assumes the user is passing a valid int
{
    tree->size++; // increments the size of the tree because something is getting added

    if (tree->size == 0) // checks if the BST is empty
    {
        tree->value = data; // sets the current trees data to be the passed in data
        return 0;           // returns because the data has been inserted succesfully
    }

    if (data < tree->value) // checks if the new data is less than the current trees data
    {
        if (tree->left == NULL) // if the left side of the tree has nothing in it
        {
            tree->left = initBST();   // initalize the left side of the tree
            tree->left->value = data; // insert the data into the left side
            return 0;                 // return 0 on success
        }

        else
            return insertBST(tree->left, data); // if the left side of the tree is not NULL, recusivly insert on that side
    }

    if (data > tree->value) // checks if new data is greater than the current trees data
    {
        if (tree->right == NULL) // checks if right side of tree has nothing in it
        {
            tree->right = initBST();   // initalizes right side of tree to be valid BST
            tree->right->value = data; // sets the data of new side of tree to be equal to the passed in data
            return 0;                  // returns 0
        }

        else
            return insertBST(tree->right, data); // recursivly inserts on the right side of the tree if the previous conditions werent met
    }

    return 1; // returns one in case nothing got inserted
}

int getSizeBST(BST *tree) // simply returns the size value stored in the BST
{
    return tree->size;
}

int getMaxBST(BST *tree) // searches the tree to find the max
{

    if (tree->right != NULL)           // if the right side of the tree is not empty
        return getMaxBST(tree->right); // recusivly iterates through right side
    return tree->value;                // returns the value stored on the longest right branch
}

void preOrderPrintBST(BST *tree) // prints the lest side, then the right side of the tree
{
    if (tree == NULL) // if the current tree is NULL returns
        return;

    printf("%d", tree->value);     // prints the value stored in the current tree
    preOrderPrintBST(tree->left);  // recursivly prints the left side of the tree
    preOrderPrintBST(tree->right); // recursivly prints the right side of the tree
}

void freeBST(BST *tree) // frees the BST
{
    if (tree == NULL) // if the current tree is null returns
        return;
    freeBST(tree->left);  // frees the left side of the current tree using recursion
    freeBST(tree->right); // frees the right side of the current tree using recursion
    free(tree);           // frees the current tree
}
