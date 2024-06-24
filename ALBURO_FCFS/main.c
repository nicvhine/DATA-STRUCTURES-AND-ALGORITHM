#include <stdio.h>
#include <stdlib.h>
#include "Fcfs.h"

int main(void) {
    FCFSQueue FQHead = create();
    populateFCFS(&FQHead);
    arrange(&FQHead);
    displayFCFS(FQHead);
    return 0;
}
