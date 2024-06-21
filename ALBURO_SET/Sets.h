#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>
#define MAX 10

typedef struct{
	bool elem[MAX];
	int count;
}Set;

Set newSet();
bool addValue(Set *s, int val);
bool deleteValue(Set *s, int val);
Set unionList(Set a, Set b);
Set intersectionList(Set a, Set b);
void display(Set s);
//void visualize(Set s);

#endif

