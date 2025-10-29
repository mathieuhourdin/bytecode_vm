#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef enum Operand {
    START,
    HALT,
    CHARGE,
    ADD
} Operand;

typedef struct Instruction {
    enum Operand operand;
    int value;
    int destination;
} Instruction;

Instruction* instruction_new(Operand operand, int value, int destination);
void read_instruction(Instruction *instruction);

#endif
