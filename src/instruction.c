#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "instruction.h"
#include "cpu.h"
#include "stack.h"
#include "instruction_operand.h"
#include "instruction_memory_location.h"

void instruction_dump(const Instruction *instruction) {
    printf("Operand %s, value : %d, destination : %s\n", operand_to_string(instruction->operand), instruction->value, memory_location_to_string(instruction->destination));
}

Instruction* instruction_new(Operand operand, int value, MemoryLocation destination) {
    Instruction *instruction = malloc(sizeof(Instruction));
    instruction->operand = operand;
    instruction->value = value;
    instruction->destination = destination;
    return instruction;
}

Instruction* instruction_parse(char *code_line) {
    code_line[strlen(code_line) - 1] = '\0';
    char *operand_string = malloc(4 * sizeof(char));
    operand_string = strncpy(operand_string, code_line, 3);
    operand_string[3] = '\0';
    Operand operand = operand_from_string(operand_string);
    free(operand_string);

    switch (operand) {
        case HALT:
        case START:
        case ADD:
        case IF:
        case CPR:
            return instruction_new(operand, 0, NO_LOCATION);
        case PULL:
        case PUSH:
            MemoryLocation destination = memory_location_from_string(code_line + 4);
            return instruction_new(operand, 0, destination);
        case CHARGE:
            int value = strtol(code_line + 4, NULL, 10);
            return instruction_new(operand, value, NO_LOCATION);
        case JMP:
            int instruction_offset = strtol(code_line + 4, NULL, 10);
            return instruction_new(operand, instruction_offset, NO_LOCATION);
    }
    return NULL;
}

