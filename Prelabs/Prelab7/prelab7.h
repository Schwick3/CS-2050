typedef struct nodeStruct
{
    void *data;
    struct nodeStruct *next;
} Node;

typedef struct queueInfoStruct
{
    Node *head;
    Node *tail;
    int errorCode;
} QueueInfo;

typedef struct queueStruct
{
    QueueInfo *queueStruct;
} Queue;

int getQueueErrorCode(Queue q);
Queue queueInit();
int enqueue(void *data, Queue); // dont forget to change to void *
void *dequeue(Queue q);         // dont forget to change to void *
int getQueueSize(Queue q);
void freeQueue(Queue q);