#ifndef PROGRAM_H
#define PROGRAM_H

typedef struct Instruction Instruction;

typedef struct Program {
    Instruction *instructions;
    int length;
    int capacity;
} Program;


/**
 * takes the path to a given code file and returns a program ready for execution by the cpu
 */
Program* program_parse(char *program_path);

/**
 * takes a copy of the pushed instruction so it doesn't take ownership.
 */
void program_push(Program *program, Instruction new_instruction);

/**
 * Prints all instructions of the program
 */
void program_dump(Program *program);

#endif
