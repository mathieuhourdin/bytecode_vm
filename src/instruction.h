#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "instruction_operand.h"
#include "instruction_memory_location.h"


typedef struct Instruction {
    enum Operand operand;
    int value;
    enum MemoryLocation destination;
} Instruction;

/**
 * returns a new instruction from operand, value and memory location
 */
Instruction* instruction_new(enum Operand operand, int value, MemoryLocation destination);

/**
 * from a line of instruction creates a new instruction
 */
Instruction* instruction_parse(char *code_line);


/**
 * from an instruction, prints the content of the instruction
 */
void instruction_dump(const Instruction *instruction);
#endif
