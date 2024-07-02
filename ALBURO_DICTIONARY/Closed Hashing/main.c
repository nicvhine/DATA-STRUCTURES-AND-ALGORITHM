#include <stdio.h>
#include <stdlib.h>
#include "CloseHashing.h"

int main(int argc, char *argv[]) {
    Closed c;
    initialize(&c);
    
    insert("Chandler", &c);
    insert("Ross", &c);
    insert("Rachel", &c);
    insert("Monica", &c);
    insert("Phoebe", &c);
    insert("Joey", &c);
    
    display(c);
    
    return 0;
}
