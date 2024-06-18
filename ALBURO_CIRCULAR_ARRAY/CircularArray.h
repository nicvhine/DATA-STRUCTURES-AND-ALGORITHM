#ifndef CIRCULARARRAY_H
#define CIRCULARARRAY_H

#define MAX 10
#define EMPTY 9999
typedef struct{
	int elem[MAX];
	int front;
	int rear;
}CircularQ;


void initializeQueue(CircularQ *q);
void enqueue(CircularQ *q, int item);
void dequeue(CircularQ *q);
int front(CircularQ q);
bool isEmpty(CircularQ q);
bool isFull(CircularQ q);
void display(CircularQ q);
void visualize(CircularQ q);	

#endif

