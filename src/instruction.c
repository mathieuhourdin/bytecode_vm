#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "instruction.h"
#include "cpu.h"
#include "stack.h"
#include "instruction_operand.h"
#include "instruction_memory_location.h"

Code* code_new() {
    Code *code = malloc(sizeof(Code));
    code->instructions = malloc(128 * sizeof(Instruction));
    code->length = 0;
    code->capacity = 128;
    return code;
}

void instruction_dump(Instruction *instruction) {
    printf("Operand %s, value : %d, destination : %s\n", operand_to_string(instruction->operand), instruction->value, memory_location_to_string(instruction->destination));
}

void code_push(Code *code, Instruction new_instruction) {
    if (code->length == code->capacity) {
        code->instructions = realloc(code->instructions, 2 * code->capacity);
        code->capacity = 2 * code->capacity;
    }
    code->instructions[code->length] = new_instruction;
    code->length++;
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
    //TODO free operand_string
    char *operand_string = malloc(4 * sizeof(char));
    operand_string = strncpy(operand_string, code_line, 3);
    operand_string[3] = '\0';
    Operand operand = operand_from_string(operand_string);

    printf("\nOperand from string : %s\n", operand_to_string(operand));

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

Code* code_parse(char *code_path) {
    FILE *file = fopen(code_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    Code *code = code_new();

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Instruction *instruction = instruction_parse(line);
        code_push(code, *instruction);
        free(instruction);
        printf("%s", line);   // fgets keeps the '\n' if present
    }
    fclose(file);
    return code;
}

void code_dump(Code *code) {

    for (int i = 0; i < code->length; i++) {
        instruction_dump(&code->instructions[i]);
    }
}
