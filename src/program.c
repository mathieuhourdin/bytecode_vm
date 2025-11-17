#include<stdlib.h>
#include <stdio.h>
#include <string.h>

#include "program.h"
#include "instruction.h"

Program* program_new() {
    Program *program = malloc(sizeof(Program));
    program->instructions = malloc(128 * sizeof(Instruction));
    program->length = 0;
    program->capacity = 128;
    return program;
}

void program_push(Program *program, Instruction new_instruction) {
    if (program->length == program->capacity) {
        program->instructions = realloc(program->instructions, 2 * program->capacity);
        program->capacity = 2 * program->capacity;
    }
    program->instructions[program->length] = new_instruction;
    program->length++;
}

Program* program_parse(char *program_path) {
    FILE *file = fopen(program_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    Program *program = program_new();

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Instruction *instruction = instruction_parse(line);
        program_push(program, *instruction);
        free(instruction);
        //printf("%s", line);   // fgets keeps the '\n' if present
    }
    fclose(file);
    return program;
}

void program_dump(Program *program) {

    for (int i = 0; i < program->length; i++) {
        instruction_dump(&program->instructions[i]);
    }
}
