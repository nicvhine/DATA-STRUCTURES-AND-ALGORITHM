#ifndef QUEUE_LINKED_LIST
#define QUEUE_LINKED_LIST
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void initQueue(Queue *queue);
Queue createQueue();

bool Enqueue(Queue *queue, int elem);
int Front(Queue *queue);
bool Dequeue(Queue *queue);
int Rear(Queue *queue);

bool isEmpty(Queue *queue);
void displayQueue(Queue *queue);

#endif
