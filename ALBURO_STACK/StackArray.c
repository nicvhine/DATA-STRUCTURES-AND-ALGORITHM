#include <stdio.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

bool isEmpty(StackArrayList *s){
	return s->top == -1;
}

bool isFull(StackArrayList *s){
	return s->top == MAX - 1;
}

void push (StackArrayList *s, Data value){
	if(isFull(s)) {
		printf("Stack Full\n");
		return;
	}
	s->elem[++(s->top)] = value;
}

void pop(StackArrayList *s){
	if(isEmpty(s)){
		printf("Stack Empty\n");
		return;
	}
	s->top--;
}

Data peek(StackArrayList *s){
	if(isEmpty(s)){
		printf("Stack Empty\n");
		return;
	}
	return s->elem[s->top];
}

void display(StackArrayList *s){
	StackArrayList newStack;
	initStack(&newStack);
	
	while(!isEmpty(s)){
		push(&newStack, peek(s));
		pop(s);
	}
	while(!isEmpty(&newStack)){
		printf("%d ", peek(&newStack));
		pop(&newStack);
	}
	printf("\n");
}

void visualize(StackArrayList *s){
	if (isEmpty(s)){
		printf("Stack Empty\n");
		return;
	}
	
	Data i;
	printf("Stack: ");
	for(i = s->top; i >= 0; i--){
		printf("%d ", s->elem[i]);
	}
	printf("\n");
}
