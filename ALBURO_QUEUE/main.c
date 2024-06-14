#include <stdio.h>
#include <stdlib.h>
#include "queueLinkedList.h"

int main(int argc, char *argv[]) {
    Queue queueList = createQueue(); 
    
  
    Enqueue(&queueList, 10);
    Enqueue(&queueList, 20);
    Enqueue(&queueList, 30);
    
  
    printf("Queue after enqueue operations:\n");
    displayQueue(&queueList);
    printf("\n");

  
    printf("Visualizing the queue:\n");
    visualizeQueue(&queueList);
    printf("\n");

   
    Dequeue(&queueList);

  
    printf("Queue after dequeue operation:\n");
    displayQueue(&queueList);
    printf("\n");

  
    printf("Visualizing the queue after dequeue operation:\n");
    visualizeQueue(&queueList);
    printf("\n");

    return 0;
}

