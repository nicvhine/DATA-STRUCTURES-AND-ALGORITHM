#include <stdio.h>
#include "Adjacency.h"

void printAdjMatrix(int adjMatrix[V][V]) {
  
    char vertexLabels[V] = {'A', 'B', 'C', 'D', 'E'};
    int i, j;

    printf("    "); 
    for(j = 0; j < V; j++) {
        printf("%c   ", vertexLabels[j]);
    }
    printf("\n");

    for(i = 0; i < V; i++) {
        printf("%c   ", vertexLabels[i]);
        for(j = 0; j < V; j++) {
            printf("%d   ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}


