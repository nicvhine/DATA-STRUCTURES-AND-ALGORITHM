#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

int main() {
    StackArrayList s;
    startStack(&s);
    addElement(&s, 1);
    addElement(&s, 10);
    addElement(&s, 20);
    addElement(&s, 30);
    printf("DISPLAY: \n");
    printStack(s);
    printf("\nVISUALIZE: \n");
    viewStack(s);
    removeEvenNumbers(&s);
    printf("DISPLAY: \n");
    printStack(s);
    return 0;
}
