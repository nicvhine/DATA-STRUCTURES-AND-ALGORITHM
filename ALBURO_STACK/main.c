#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

int main() {
    StackArrayList s;
    startStack(&s);
    addElement(&s, 10);
    addElement(&s, 20);
    addElement(&s, 30);
    printf("DISPLAY: \n");
    printStack(s);
    printf("VISUALIZE: \n");
    viewStack(s);
    return 0;
}
