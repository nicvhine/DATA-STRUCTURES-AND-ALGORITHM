#ifndef CLOSED_HASHING
#define CLOSED_HASHING

#include <stdbool.h>

#define MAX_STRING_LENGTH 50 

typedef struct {
    char string[MAX_STRING_LENGTH];
    bool occupied;
} Entry;

typedef struct {
    Entry *hashTable;
    int size;
    float threshold;
    int count;
} Closed;

void initialize(Closed *c);
bool threshold(Closed c);
void insert(char string[], Closed *c);
unsigned int hashValue(char string[], Closed c);
void display(Closed c);

#endif
