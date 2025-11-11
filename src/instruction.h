#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "instruction_operand.h"
#include "instruction_memory_location.h"


typedef struct Instruction {
    enum Operand operand;
    int value;
    enum MemoryLocation destination;
    struct Instruction *next;
} Instruction;

typedef struct Code {
    Instruction *instructions;
    int length;
    int capacity;
} Code;

/**
 * returns a new instruction from operand, value and memory location
 */
Instruction* instruction_new(enum Operand operand, int value, MemoryLocation destination);

/**
 * takes the path to a given code file and returns a program ready for execution by the cpu
 */
Code* code_parse(char *code_path);

/**
 * takes a copy of the pushed instruction so it doesn't take ownership.
 */
void code_push(Code *code, Instruction new_instruction);

/**
 * Prints all instructions of the code
 */
void code_dump(Code *code);

#endif
