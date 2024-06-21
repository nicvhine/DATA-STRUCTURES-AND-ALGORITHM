#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Sets.h"

Set newSet(){
	int i;
	Set s;
	
	s.count = 0;
	
	for(i = 0; i < MAX; i++){
		s.elem[i] = 0;
	}
	
	return s;
}

bool addValue(Set *s, int val){
	s -> elem[val] = 1;
	s -> count++;
	
	return true;
}

bool deleteValue(Set *s, int val){
	s -> elem[val] = 0; 
	s -> count--;
	
	return true;
}

Set unionList(Set a, Set b){
	Set result = newSet();
	int i;
	
	for(i = 0; i < MAX; i++){
		if(a.elem[i] || b.elem[i]){
			addValue(&result, i);
		}
	}
	
	return result;
}

Set intersectionList(Set a, Set b){
	Set result = newSet();
	int i;
	
	for(i = 0; i < MAX; i++){
		if(a.elem[i] && b.elem[i]){
			addValue(&result, i);
		}
	}
	
	return result;
}

void display(Set s){
	int i;
	
	for(i = 0; i < MAX; i++){
		if(s.elem[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}
//void visualize(Set s){
//	
//}

