#ifndef FCFS_QUEUE
#define FCFS_QUEUE

#include <stdbool.h>

typedef struct {
    char p;
    int bt;
    int at;
} Process;

typedef struct node {
    Process p;
    struct node *next;
} ProcessNode, *ProcessNodePtr;

typedef struct {
    ProcessNodePtr first;
    ProcessNodePtr last;
} FCFSQueue;

FCFSQueue create();
void initFCFS(FCFSQueue *q);
void populateFCFS(FCFSQueue *q);
void arrange(FCFSQueue *q);
bool enqueue(FCFSQueue *q, Process p);
ProcessNodePtr first(FCFSQueue q);
bool dequeue(FCFSQueue *q);
ProcessNodePtr last(FCFSQueue q);
bool isEmpty(FCFSQueue q);
void displayFCFS(FCFSQueue q);

#endif
