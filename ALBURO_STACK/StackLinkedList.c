#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} StackLinkedList;

void startStack(StackLinkedList* s) {
    s->top = NULL;
}

bool checkEmpty(StackLinkedList* s) {
    return s->top == NULL;
}

void push(StackLinkedList* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to push element.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

bool pop(StackLinkedList* s) {
    if (checkEmpty(s)) {
        printf("Stack underflow. Unable to pop element.\n");
        return false;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return true;
}

int peek(StackLinkedList* s) {
    if (checkEmpty(s)) {
        printf("Stack is empty. Unable to peek.\n");
        return -1;
    }
    return s->top->data;
}

void printStack(StackLinkedList* s) {
    if (checkEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    StackLinkedList stack;
    startStack(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printStack(&stack);
    
    pop(&stack);
    printStack(&stack);
    
    printf("Top element of the stack: %d\n", peek(&stack));
    
    return 0;
}
