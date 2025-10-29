#include <stdlib.h>
#include <stdio.h>

#include "src/register.h"
#include "src/instruction.h"



int main() {

    my_register = register_new();

    Instruction *charge_2 = instruction_new(CHARGE, 2, 1);
    Instruction *charge_3 = instruction_new(CHARGE, 3, 2);
    Instruction *add = instruction_new(ADD, 0, 0);

    read_instruction(charge_2);
    read_instruction(charge_3);
    read_instruction(add);

    printf("Return value : %d\n", my_register->rg1);
}




