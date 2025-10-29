#ifndef STACK_H
#define STACK_H


typedef struct StackSegment {
    int segment[10];
} StackSegment;

extern StackSegment *stacksegment;

StackSegment* stacksegment_new();
void stacksegment_push(int value, int index);
int stacksegment_pull(int index);

#endif
