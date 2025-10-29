#include <stdlib.h>
#include <stdio.h>

#include "src/register.h"
#include "src/instruction.h"
#include "src/stack.h"



int main() {

    Instruction *start = instruction_new(START, 0, NO_LOCATION);
    Instruction *charge_2 = instruction_new(CHARGE, 2, REGISTER_1);
    Instruction *charge_3 = instruction_new(CHARGE, 3, REGISTER_2);
    Instruction *add = instruction_new(ADD, 0, NO_LOCATION);
    Instruction *push_stack_1 = instruction_new(PUSH, 0, STACK_1);
    Instruction *charge_4 = instruction_new(CHARGE, 4, REGISTER_1);
    Instruction *charge_stack_1 = instruction_new(PULL, 0, STACK_1);
    Instruction *push_stack_0 = instruction_new(PUSH, 0, STACK_0);
    Instruction *halt = instruction_new(HALT, 0, NO_LOCATION);

    read_instruction(start);
    read_instruction(charge_2);
    read_instruction(charge_3);
    read_instruction(add);
    read_instruction(push_stack_1);
    read_instruction(charge_4);
    read_instruction(charge_stack_1);
    read_instruction(push_stack_0);
    read_instruction(add);
    read_instruction(halt);

    printf("Return value : %d\n", my_register->rg1);
}




