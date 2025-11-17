#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "instruction.h"
#include "cpu.h"
#include "stack.h"
#include "instruction_opcode.h"
#include "instruction_memory_location.h"

void instruction_dump(const Instruction *instruction) {
    printf("Opcode %s, value : %d, destination : %s\n", opcode_to_string(instruction->opcode), instruction->value, memory_location_to_string(instruction->destination));
}

Instruction* instruction_new(Opcode opcode, int value, MemoryLocation destination) {
    Instruction *instruction = malloc(sizeof(Instruction));
    instruction->opcode = opcode;
    instruction->value = value;
    instruction->destination = destination;
    return instruction;
}

Instruction* instruction_parse(char *code_line) {
    code_line[strlen(code_line) - 1] = '\0';
    char *opcode_string = malloc(4 * sizeof(char));
    opcode_string = strncpy(opcode_string, code_line, 3);
    opcode_string[3] = '\0';
    Opcode opcode = opcode_from_string(opcode_string);
    free(opcode_string);

    switch (opcode) {
        case HALT:
        case START:
        case ADD:
        case IF:
        case CPR:
        case SET:
            return instruction_new(opcode, 0, NO_LOCATION);
        case PULL:
        case PUSH:
            MemoryLocation destination = memory_location_from_string(code_line + 4);
            return instruction_new(opcode, 0, destination);
        case CHARGE:
            int value = strtol(code_line + 4, NULL, 10);
            return instruction_new(opcode, value, NO_LOCATION);
        case JMP:
            int instruction_offset = strtol(code_line + 4, NULL, 10);
            return instruction_new(opcode, instruction_offset, NO_LOCATION);
    }
    return NULL;
}

