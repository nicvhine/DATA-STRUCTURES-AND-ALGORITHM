#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} StackArrayList;

void startStack(StackArrayList *s);

bool checkEmpty(StackArrayList *s);
bool checkFull(StackArrayList *s);

bool addElement(StackArrayList *s, int value);
bool removeElement(StackArrayList *s);
int peekTop(StackArrayList s);

void printStack(StackArrayList s);
void viewStack(StackArrayList s);
void removeEvenNumbers(StackArrayList *s);

#endif

