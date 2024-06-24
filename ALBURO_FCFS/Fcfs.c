#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Fcfs.h"

FCFSQueue create() {
    FCFSQueue q;
    initFCFS(&q);
    return q;
}

void initFCFS(FCFSQueue *q) {
    q->first = q->last = NULL;
}

void populateFCFS(FCFSQueue *q) {
    int input, i;
    Process p;

    printf("Enter number of processes: ");
    scanf("%d", &input);
    printf("\n");

    for (i = 0; i < input; i++) {
        printf("Process %c\n", 'A' + i);
        p.p = 'A' + i;

        printf("Enter Burst Time: ");
        scanf("%d", &p.bt);

        printf("Enter Arrival Time: ");
        scanf("%d", &p.at);

        enqueue(q, p);
        printf("\n");
    }
}

void arrange(FCFSQueue *q) {
    FCFSQueue temp = create();
    while (!isEmpty(*q)) {
        ProcessNodePtr check = first(*q);
        enqueue(&temp, check->p);
        dequeue(q);
    }
    *q = temp;
}


bool enqueue(FCFSQueue *q, Process p) {
    ProcessNodePtr temp = (ProcessNodePtr)malloc(sizeof(ProcessNode));
    
    if (temp == NULL) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    return false; 
}
    
    temp->p = p;
    temp->next = NULL;
    
    if (isEmpty(*q)) {
        q->first = q->last = temp;
    } else {
        q->last->next = temp;
        q->last = temp;
    }
    
    return true;
}

bool dequeue(FCFSQueue *q) {
    if (isEmpty(*q)) {
        return false;
    }
    
    ProcessNodePtr temp = q->first;
    q->first = q->first->next;
    
    if (q->first == NULL) {
        q->last = NULL;
    }
    
    free(temp);
    return true;
}

ProcessNodePtr first(FCFSQueue q) {
    return q.first;
}

ProcessNodePtr last(FCFSQueue q) {
    return q.last;
}

bool isEmpty(FCFSQueue q) {
    return q.first == NULL && q.last == NULL;
}

void displayFCFS(FCFSQueue q) {
    if (isEmpty(q)) {
        printf("FCFS Queue is Empty!\n");
        return;
    }

    printf("╔════════════╦════════════╦═══════════════╦═════════════════╦══════════════╦═════════════════╗\n");

    printf("║ Process ID ║ Burst Time ║ Arrival Time  ║ Completion Time ║ Waiting Time ║ Turnaround Time ║\n");

    printf("╠════════════╬════════════╬═══════════════╬═════════════════╬══════════════╬═════════════════╣\n");

    int wtTotal = 0, ttTotal = 0, count = 0;
    int ct = 0, wt, tt;
    ProcessNode *temp = q.first;

    while (temp != NULL) {
        Process p = temp->p;

        int completionTime = ct + p.bt;
        wt = ct - p.at;
        tt = completionTime - p.at;

        wtTotal += wt;
        ttTotal += tt;

        printf("║     %c      ║     %2d     ║      %2d       ║       %2d        ║      %2d      ║       %2d        ║\n",
               p.p, p.bt, p.at, completionTime, wt, tt);

        ct = completionTime;
        temp = temp->next;
        count++;
    }

    printf("╚════════════╩════════════╩═══════════════╩═════════════════╩══════════════╩═════════════════╝\n");

    printf("                                  Total                           %2d                %2d\n", wtTotal, ttTotal);
    printf("                                  Average                         %.2f             %.2f\n", (float) wtTotal / count, (float) ttTotal / count);
}