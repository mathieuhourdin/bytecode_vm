#include <stdlib.h>
#include <stdio.h>

#include "instruction.h"
#include "register.h"
#include "stack.h"

Instruction* instruction_new(Operand operand, int value, MemoryLocation destination) {
    Instruction *instruction = malloc(sizeof(Instruction));
    instruction->operand = operand;
    instruction->value = value;
    instruction->destination = destination;
    return instruction;
}

void read_instruction(Instruction *instruction) {
    switch (instruction->operand) {
        case START:
            stacksegment = stacksegment_new();
            my_register = register_new();
            break;
        case CHARGE:
            register_charge(instruction->value);
            break;
        case ADD:
            register_add();
            break;
        case PUSH:
            int value = register_get_last_value();
            stacksegment_push(value, instruction->destination);
            break;
        case PULL:
            int pull_value = stacksegment_pull(instruction->destination);
            register_charge(pull_value);
            break;
        case HALT:
            printf("Result of the program : %d\n", register_get_last_value());
            break;
    }
}

