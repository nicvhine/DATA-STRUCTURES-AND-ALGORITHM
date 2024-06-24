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

    printf("Enter number of process: ");
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
    ProcessNodePtr check, front;
    
    while (!isEmpty(*q)) {
        check = first(*q);
        front = check;
        
        if (front == NULL || check->p.at < front->p.at) {
            enqueue(&temp, check->p);
            dequeue(q);
        } else {
            enqueue(q, check->p);
            dequeue(q);
        }
    }
    
    *q = temp;
}

bool enqueue(FCFSQueue *q, Process p) {
    bool res = false;
    ProcessNodePtr temp = (ProcessNodePtr)malloc(sizeof(ProcessNode));
    
    if (temp != NULL) {
        temp->p = p;
        temp->next = NULL;
        
        if (isEmpty(*q)) {
            q->first = q->last = temp;
        } else {
            q->last->next = temp;
            q->last = temp;
        }
        
        res = true;
    }
    
    return res;
}

bool dequeue(FCFSQueue *q) {
    bool res = false;
    ProcessNodePtr temp;
    
    if (!isEmpty(*q)) {
        temp = q->first;
        q->first = temp->next;
        free(temp);
        
        if (q->first == NULL) {
            q->last = NULL;
        }
        
        res = true;
    }
    
    return res;
}

ProcessNodePtr first(FCFSQueue q) {
    return (!isEmpty(q)) ? q.first : NULL;
}

ProcessNodePtr last(FCFSQueue q) {
    return (!isEmpty(q)) ? q.last : NULL;
}

bool isEmpty(FCFSQueue q) {
    return (q.first == NULL && q.last == NULL);
}

void displayFCFS(FCFSQueue q) {
    if (!isEmpty(q)) {
        printf("FCFS Queue Visualization\n");
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
        printf("| Process ID | Burst Time | Arrival Time | Execution Time | Waiting Time | Turnaround Time |\n");
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");

        int count = 0, ct = 0, et, wt, tt, wtTotal = 0, ttTotal = 0;
        ProcessNodePtr temp = q.first;

        while (temp != NULL) {
            Process p = temp->p;

            if (ct < p.at) {
                ct = p.at;
            }

            wt = ct - p.at;
            et = ct;
            tt = et + p.bt;
            ct += p.bt;

            wtTotal += wt;
            ttTotal += tt;

            printf("| %-10c | %-10d | %-12d | %-14d | %-12d | %-15d |\n", p.p,
                   p.bt,
                   p.at,
                   et,
                   wt,
                   tt);

            temp = temp->next;
            count++;
        }

        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
        printf("| %-10s | %-10s | %-12s | %-14s | %-12d | %-15d |\n", "", "", "", "Total ", wtTotal, ttTotal);
        printf("| %-10s | %-10s | %-12s | %-14s | %-12.2f | %-15.2f |\n", "", "", "", "Average ", (float)wtTotal / count, (float)ttTotal / count);
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
    } else {
        printf("FCFS is Empty!\n");
    }
}

