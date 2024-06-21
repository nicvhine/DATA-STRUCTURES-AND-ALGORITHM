#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Sets.h"

int main() {
	Set unionSet, intersectionSet;
	
	Set a = newSet();
	Set b = newSet();
	
	addValue(&a, 1);
    addValue(&a, 2);
    addValue(&a, 3);
    addValue(&a, 4);
    
    addValue(&b, 1);
    addValue(&b, 2);
    addValue(&b, 4);
    addValue(&b, 5);
    addValue(&b, 6);
    addValue(&b, 7);
    
    printf("Set A\n");
    	display(a);
    
    printf("\n");
    
    printf("Set B\n");
    	display(b);
    	
    printf("\n");
    
    unionSet = unionList(a,b);
    intersectionSet = intersectionList(a,b);
    
    printf("UNION\n");
    	display(unionSet);
    	
    printf("\n");
    
    printf("INTERSECTION\n");
    	display(intersectionSet);
    	
//    printf("\n\nVisualize Set A: "); visualize(a);
//    printf("\n\nVisualize Set B: "); visualize(b);
//    printf("\n\n");

	return 0;
}
