#ifndef OPEN_HASHING
#define OPEN_HASHING

#include <stdbool.h>

typedef struct node {
    char string[50]; 
    struct node *next;
} NODE, *NODEPTR;

typedef struct {
    NODEPTR *hashTable;
    int count;
    int size;
    float threshold;
} Open;

void initialize(Open *o);
bool threshold(Open o);
void insert(char string[], Open *o);
unsigned int hashValue(char string[], Open o);
void display(Open o);

#endif
