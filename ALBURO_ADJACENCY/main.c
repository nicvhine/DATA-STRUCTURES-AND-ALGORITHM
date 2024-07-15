#include <stdio.h>
#include "Adjacency.h"

int main() {
	int adjMatrix[V][V] = {0};
	
	int A = 0, B = 1, C = 2, D = 3, E = 4;
	adjMatrix[A][C] = 1;
	adjMatrix[C][A] = 1;
	adjMatrix[B][C] = 1;
	adjMatrix[C][B] = 1;
	adjMatrix[B][E] = 1;
	adjMatrix[E][B] = 1;
	adjMatrix[E][D] = 1;
	adjMatrix[D][E] = 1;
	adjMatrix[A][D] = 1;
	adjMatrix[D][A] = 1;
	adjMatrix[A][B] = 1;
	adjMatrix[B][A] = 1;
	adjMatrix[D][C] = 1;
	adjMatrix[C][D] = 1;
	adjMatrix[D][B] = 1;
	adjMatrix[B][D] = 1;
	
	printf("Adjacency Matrix:\n");
	printAdjMatrix(adjMatrix);
}
