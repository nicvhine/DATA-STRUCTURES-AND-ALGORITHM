#include <stdio.h>
#include <stdlib.h>
#include "OpenHashing.h"


int main(int argc, char *argv[]) {
	Open o;
	initialize(&o);
	insert("Chandler", &o);
	insert("Ross", &o);
	insert("Rachel", &o);
	insert("Monica", &o);
	insert("Phoebe", &o);
	insert("Joey", &o);
	display(o);
	return 0;
}