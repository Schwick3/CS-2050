typedef struct listStruct
{
    int object;
    struct listStruct *next;
} List;

List *initList(int *errorCode);
List *insertAtHead(int object, List *node, int *errorCode);
int getAtIndex(int index, List *node);
int getListLength(List *node);
List *freeList(List *node);