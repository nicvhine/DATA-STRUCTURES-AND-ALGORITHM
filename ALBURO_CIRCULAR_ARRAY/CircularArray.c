#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "CircularArray.h"

void initializeQueue(CircularQ *q){
	q -> front = 6;
	q -> rear = 5;
	int i;
	
	for(i = 0; i < MAX; i++){
		q -> elem[i] = EMPTY;
	}
}

void enqueue(CircularQ *q, int item){
	if(!isFull(*q)){
		q -> rear = (q -> rear + 1) % MAX;
		q -> elem[q -> rear] = item;
	}
}

void dequeue(CircularQ *q){
	if(!isEmpty(*q)){
		q -> elem[q -> front] = EMPTY;
		q -> front = (q -> front + 1) % MAX;
	}
}

int front(CircularQ q){
	if(!isEmpty(q)){
		return q.elem[q.front];
	}
	return EMPTY;
}

bool isEmpty(CircularQ q){
	return (q.rear + 1) % MAX == q.front;
}

bool isFull(CircularQ q){
	return (q.rear + 2) % MAX == q.front;
}

void display(CircularQ q){
	int i;
	printf("DISPLAY\n\n");
	for(i = 0; i < MAX; i++){
		if(q.elem[i] != EMPTY){
			printf("%d\n", q.elem[i]);
		}else{
			printf("");
		}
	}
	printf("\n");
}

void visualize(CircularQ q){
	printf("VISUALIZE\n");
	printf("\n%3s | %3s | %s\n", "INDEX", "VALUE", "POSITION");
	
	int i;
	for(i=0; i<MAX; i++){
		printf("%5d | ", i);
		if(q.elem[i] != EMPTY){
			printf("%5d | ", q.elem[i]);
		}else{
			printf("%5s | ", " ");
		}
			if(i == q.front){
				printf("Front");
			} if(i == q.rear){
				printf("Rear");
			}
		
		printf("\n");
	}
	printf("\n");
}
