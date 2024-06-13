#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	StackArrayList s;
	initStack(&s);
	
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	visualize(&s);
	
	Data peekValue = peek(&s);
	printf("Top: ", peekValue);
	
	pop(&s);
	visualize(&s);
	
	printf("Function Stack: \n");
	display(&s);
	return 0;
}
