#include <stdlib.h>
#include <stdio.h>


typedef struct StackItem {
    int value;
    struct StackItem *next;
} StackItem;

StackItem* stackitem_new(int value) {
    StackItem *stackitem = malloc(sizeof(StackItem));
    stackitem->value = value;
    stackitem->next = NULL;
    return stackitem;
}

typedef struct Stack {
    StackItem *first_item;
} Stack;

Stack* stack_new() {
    Stack *stack = malloc(sizeof(Stack));
    stack->first_item = NULL;
    return stack;
}

typedef enum Operand {
    START,
    HALT,
    CHARGE,
    ADD
} Operand;

typedef struct Instruction {
    enum Operand operand;
    int value;
} Instruction;

Instruction* instruction_new(Operand operand, int value) {
    Instruction *instruction = malloc(sizeof(Instruction));
    instruction->operand = operand;
    instruction->value = value;
    return instruction;
}

void stack_push(Stack *stack, int value) {
    StackItem *stackitem = stackitem_new(value);
    if (stack->first_item) {
        stackitem->next = stack->first_item;
    }
    stack->first_item = stackitem;
}

StackItem* stack_pop(Stack *stack) {
    StackItem *stackitem = stack->first_item;
    if (stackitem) {
        stack->first_item = stackitem->next;
    }
    return stackitem;
}

void read_instruction(Instruction *instruction, Stack *stack) {
    if (instruction->operand == CHARGE) {
        stack_push(stack, instruction->value);
    } else if (instruction->operand == ADD) {
        StackItem *stackitem_1 = stack_pop(stack);
        StackItem *stackitem_2 = stack_pop(stack);
        stack_push(stack, stackitem_1->value + stackitem_2->value);
    }
}

int main() {
    Stack *stack = stack_new();

    Instruction *charge_2 = instruction_new(CHARGE, 2);
    Instruction *charge_3 = instruction_new(CHARGE, 3);
    Instruction *add = instruction_new(ADD, 0);

    read_instruction(charge_2, stack);
    read_instruction(charge_3, stack);
    read_instruction(add, stack);

    printf("Return value : %d\n", stack->first_item->value);
}




