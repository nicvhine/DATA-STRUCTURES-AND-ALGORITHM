#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "StackArray.h"

void startStack(StackArrayList *s) {
    s->top = -1;
}

StackArrayList formStack() {
    StackArrayList s;
    startStack(&s);
    return s;
}

bool checkEmpty(StackArrayList *s) {
    return s->top == -1;
}

bool checkFull(StackArrayList *s) {
    return s->top == MAX - 1;
}

bool addElement(StackArrayList *s, int value) {
    if (checkFull(s)) {
        printf("Stack Overflow.\n");
        return false;
    }
    s->data[++s->top] = value;
    return true;
}

bool removeElement(StackArrayList *s) {
    if (checkEmpty(s)) {
        printf("Stack Underflow.\n");
        return false;
    }
    s->top--;
    return true;
}

int peekTop(StackArrayList s) {
    if (checkEmpty(&s)) {
        printf("Stack is Empty.\n");
        return -1;
    }
    return s.data[s.top];
}

void printStack(StackArrayList s) {
    StackArrayList newStack;
    startStack(&newStack);
    while (!checkEmpty(&s)) {
        addElement(&newStack, peekTop(s));
        removeElement(&s);
    }
    while (!checkEmpty(&newStack)) {
        printf("%d \n", peekTop(newStack));
        removeElement(&newStack);
    }
    printf("\n");
}

void viewStack(StackArrayList s) {
    if (checkEmpty(&s)) {
        printf("Stack is Empty.\n");
    }
    for (int i = s.top; i >= 0; i--) {
        printf("%d %d", s.data[i], i);
        if (s.data[i] != s.top) {
            printf("%4s \n", " <-- top");
        }
    }
    printf("\n");
}
