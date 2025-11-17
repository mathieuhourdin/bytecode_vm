#ifndef INSTRUCTION_OPCODE_H
#define INSTRUCTION_OPCODE_H

typedef enum Opcode {
    START,
    HALT,
    CHARGE,
    ADD,
    PUSH,
    PULL,
    IF,
    CPR,
    JMP,
    SET
} Opcode;

Opcode opcode_from_string(char* str);
char* opcode_to_string(Opcode opcode);

#endif
