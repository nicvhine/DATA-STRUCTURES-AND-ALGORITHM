#include <stdio.h>
#include <stdlib.h>
#include "queueLinkedList.h"


void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}


Queue createQueue() {
    Queue queue;
    initQueue(&queue);
    return queue;
}


bool Enqueue(Queue *queue, int elem) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }
    newNode->data = elem;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return true;
}


int Front(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->front->data;
    }
    
}

bool Dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        NodePtr temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        if (queue->front == NULL) {
            queue->rear = NULL; 
        }
        return true;
    }
    return false;
}

bool isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    NodePtr current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void visualizeQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    NodePtr current = queue->front;
    printf("Front ---> ");
    while (current != NULL) {
        printf("[%d] ---> ", current->data);
        current = current->next;
    }
    printf("Rear\n");
}

;
