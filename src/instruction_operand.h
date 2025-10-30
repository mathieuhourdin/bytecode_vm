#ifndef INSTRUCTION_OPERAND_H
#define INSTRUCTION_OPERAND_H

typedef enum Operand {
    START,
    HALT,
    CHARGE,
    ADD,
    PUSH,
    PULL
} Operand;

Operand operand_from_string(char* str);
char* operand_to_string(Operand operand);

#endif
