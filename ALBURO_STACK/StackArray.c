#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "StackArray.h"

void startStack(StackArrayList *s) {
    s->top = -1;
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
    if (checkEmpty(&s)) {
        printf("Stack is Empty.\n");
        return;
    }
    printf("Top: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

void viewStack(StackArrayList s) {
    if (checkEmpty(&s)) {
        printf("Stack is Empty.\n");
        return;
    }
    
    for (int i = s.top; i >= 0; i--) {
        printf("%d <--- %d\n", s.data[i], i);
    }
    printf("\n");
}


void removeEvenNumbers(StackArrayList *s) {
    StackArrayList tempStack;
    startStack(&tempStack);
    while (!checkEmpty(s)) {
        int num = peekTop(*s);
        removeElement(s);
        if (num % 2 != 0) {
            addElement(&tempStack, num);
        }
    }
    while (!checkEmpty(&tempStack)) {
        addElement(s, peekTop(tempStack));
        removeElement(&tempStack);
    }
}

