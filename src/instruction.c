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
    code->first_instruction = NULL;
    return code;
}

void code_push(Code *code, Instruction *new_instruction) {
    Instruction *instruction = code->first_instruction;
    if (instruction == NULL) {
        code->first_instruction = new_instruction;
        return;
    }
    while (instruction->next) {
        instruction = instruction->next;
    }
    instruction->next = new_instruction;
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
    int i = 0;
    char *operand_string = malloc(6 * sizeof(char));
    while (code_line[i] != '\0' && code_line[i] != '\n' && code_line[i] != ' ') {
        i++;
    }
    operand_string = strncpy(operand_string, code_line, i);
    Operand operand = operand_from_string(operand_string);

    switch (operand) {
        case HALT:
        case START:
        case ADD:
            return instruction_new(operand, 0, NO_LOCATION);
        case PULL:
        case PUSH:
            MemoryLocation destination = memory_location_from_string(code_line + i + 1);
            return instruction_new(operand, 0, destination);
        case CHARGE:
            int value = strtol(code_line + i + 1, NULL, 10);
            return instruction_new(operand, value, NO_LOCATION);
    }
    return NULL;
}

void instruction_dump(Instruction *instruction) {
    printf("Operand %s, value : %d, destination : %s\n", operand_to_string(instruction->operand), instruction->value, memory_location_to_string(instruction->destination));
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
        code_push(code, instruction);
        printf("%s", line);   // fgets keeps the '\n' if present
    }
    fclose(file);
    return code;
}

void code_dump(Code *code) {
    Instruction *instruction = code->first_instruction;
    while(instruction) {
        instruction_dump(instruction);
        instruction =  instruction->next;
    }
}

void instruction_execute(Instruction *instruction) {
    switch (instruction->operand) {
        case START:
            stacksegment = stacksegment_new();
            cpu = cpu_new();
            break;
        case CHARGE:
            cpu_register_charge(instruction->value);
            break;
        case ADD:
            cpu_add();
            break;
        case PUSH:
            int value = cpu_register_get_last_value();
            stacksegment_push(value, instruction->destination);
            break;
        case PULL:
            int pull_value = stacksegment_pull(instruction->destination);
            cpu_register_charge(pull_value);
            break;
        case HALT:
            printf("Result of the program : %d\n", cpu_register_get_last_value());
            break;
    }
}

void code_execute(Code *code) {
    Instruction *instruction = code->first_instruction;
    while (instruction) {
        instruction_execute(instruction);
        instruction = instruction->next;
    }
}

