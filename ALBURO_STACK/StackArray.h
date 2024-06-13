#ifndef STACK_ARRAY
#define STACK_ARRAY

#define MAX 20

typedef int Data;

typedef struct{
	Data elem[MAX];
	int top;
}StackArrayList;

void initStack(StackArrayList *s);
bool isEmpty(StackArrayList *s);
bool isFull(StackArrayList *s);
void push(StackArrayList *s, Data value);
void pop(StackArrayList *s);
Data peek(StackArrayList *s);
void display(StackArrayList *s);
void visualize(StackArrayList *s);

#endif
