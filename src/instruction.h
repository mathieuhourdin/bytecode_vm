#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef enum Operand {
    START,
    HALT,
    CHARGE,
    ADD,
    PUSH,
    PULL
} Operand;

typedef enum MemoryLocation {
    REGISTER_1 = 1,
    REGISTER_2 = 2,
    STACK_0 = 0,
    STACK_1 = 1,
    STACK_2 = 2,
    STACK_3 = 3,
    STACK_4 = 4,
    STACK_5 = 5,
    STACK_6 = 6,
    STACK_7 = 7,
    STACK_8 = 8,
    STACK_9 = 9,
    NO_LOCATION
} MemoryLocation;

typedef struct Instruction {
    enum Operand operand;
    int value;
    enum MemoryLocation destination;
} Instruction;

Instruction* instruction_new(Operand operand, int value, MemoryLocation destination);
void read_instruction(Instruction *instruction);

#endif
