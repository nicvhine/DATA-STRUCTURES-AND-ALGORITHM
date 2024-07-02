#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "CloseHashing.h"

void display(Closed c) {
    printf("Closed Hashing Dictionary:\n");
    for (int x = 0; x < c.size; x++) {
        if (c.hashTable[x].occupied) {
            printf("[%d]: %s\n", x, c.hashTable[x].string);
        } else {
            printf("[%d]: Empty\n", x);
        }
    }
}

void insert(char string[], Closed *c) {
    if (!threshold(*c)) {
        unsigned int hashIndex = hashValue(string, *c);
        int originalIndex = hashIndex;
        int i = 1;
        while (c->hashTable[hashIndex].occupied) {
            hashIndex = (originalIndex + i) % c->size;
            i++;
        }
        strcpy(c->hashTable[hashIndex].string, string);
        c->hashTable[hashIndex].occupied = true;
        c->count++;
    }
}

unsigned int hashValue(char string[], Closed c) {
    unsigned int hash = 0;
    for (int x = 0; x < strlen(string); x++) {
        hash = 31 + hash + string[x];
    }
    return hash % c.size;
}

bool threshold(Closed c) {
    return ((float)c.count / c.size > c.threshold);
}

void initialize(Closed *c) {
    c->size = 10;
    c->hashTable = malloc(sizeof(Entry) * c->size);
    if (c->hashTable != NULL) {
        for (int x = 0; x < c->size; x++) {
            c->hashTable[x].occupied = false;
        }
        c->threshold = 0.65;
        c->count = 0;
    }
}
