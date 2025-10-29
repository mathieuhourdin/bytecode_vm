#include <stdlib.h>


#include "stack.h"

StackSegment* stacksegment = NULL;

StackSegment* stacksegment_new() {
    StackSegment *stacksegment = malloc(sizeof(StackSegment));
    return stacksegment;
}

void stacksegment_push(int value, int index) {
    stacksegment->segment[index] = value;
}

int stacksegment_pull(int index) {
    return stacksegment->segment[index];
}
