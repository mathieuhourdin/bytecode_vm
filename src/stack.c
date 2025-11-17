#include <stdlib.h>


#include "stack.h"

StackSegment* stacksegment_new() {
    StackSegment *stacksegment = malloc(sizeof(StackSegment));
    return stacksegment;
}

void stacksegment_push(StackSegment *stacksegment, int value, int index) {
    stacksegment->segment[index] = value;
}

int stacksegment_pull(StackSegment *stacksegment, int index) {
    return stacksegment->segment[index];
}
