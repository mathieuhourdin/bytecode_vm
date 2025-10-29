#include <stdlib.h>

#include "instruction.h"
#include "register.h"

Instruction* instruction_new(Operand operand, int value, int destination) {
    Instruction *instruction = malloc(sizeof(Instruction));
    instruction->operand = operand;
    instruction->value = value;
    instruction->destination = destination;
    return instruction;
}

void read_instruction(Instruction *instruction) {
    if (instruction->operand == CHARGE) {
        if (instruction->destination == 1) {
            my_register->rg1 = instruction->value;
        } else if (instruction->destination == 2) {
            my_register->rg2 = instruction->value;
        }
    } else if (instruction->operand == ADD) {
        my_register->rg1 += my_register->rg2;
    }
}

