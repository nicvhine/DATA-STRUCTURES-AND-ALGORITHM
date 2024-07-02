#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "OpenHashing.h"

void display(Open o) {
    printf("Open Hashing Dictionary:\n");
    for (int x = 0; x < o.size; x++) {
        printf("[%d]: ", x);
        NODEPTR current = o.hashTable[x];
        while (current != NULL) {
            printf("%s -> ", current->string);
            current = current->next;
        }
        printf("\n");
    }
}

void insert(char string[], Open *o) {
    if (!threshold(*o)) {
        unsigned int hashIndex = hashValue(string, *o);
        NODEPTR temp = (NODEPTR)malloc(sizeof(NODE));
        if (temp != NULL) {
            strcpy(temp->string, string);
            temp->next = NULL;
            NODEPTR *trav = &(o->hashTable[hashIndex]);
            while (*trav != NULL && strcmp(temp->string, (*trav)->string) > 0) {
                trav = &(*trav)->next;
            }
            temp->next = *trav;
            *trav = temp;
            o->count++;
        }
    }
}

unsigned int hashValue(char string[], Open o) {
    unsigned int hash = 0;
    for (int x = 0; x < strlen(string); x++) {
        hash = 31 + hash + string[x];
    }
    return hash % o.size;
}

bool threshold(Open o) {
    return ((float)o.count / o.size > o.threshold);
}

void initialize(Open *o) {
    o->size = 10;
    o->hashTable = malloc(sizeof(NODEPTR) * o->size);
    if (o->hashTable != NULL) {
        for (int x = 0; x < o->size; x++) {
            o->hashTable[x] = NULL;
        }
        o->threshold = 0.65;
        o->count = 0;
    }
}
