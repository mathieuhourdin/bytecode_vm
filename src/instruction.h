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
    Instruction *first_instruction;
} Code;

Instruction* instruction_new(enum Operand operand, int value, MemoryLocation destination);
void instruction_execute(Instruction *instruction);
Code* code_parse(char *code_path);
void code_dump(Code *code);
void code_execute(Code *code);

#endif
