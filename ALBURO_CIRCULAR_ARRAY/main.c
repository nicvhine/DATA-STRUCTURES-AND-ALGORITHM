#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "CircularArray.h"

int main() {
	
	CircularQ q;
	initializeQueue(&q);
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);

	display(q);
	visualize(q);
	return 0;
}
