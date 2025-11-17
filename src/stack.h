#ifndef STACK_H
#define STACK_H


typedef struct StackSegment {
    int segment[10];
} StackSegment;

StackSegment* stacksegment_new();
void stacksegment_push(StackSegment *stacksegment, int value, int index);
int stacksegment_pull(StackSegment *stacksegment, int index);

#endif
