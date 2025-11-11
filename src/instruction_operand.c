#include <string.h>

#include "instruction_operand.h"

Operand operand_from_string(char* str) {
    if (strcmp(str, "STT") == 0) return START;
    if (strcmp(str, "CHG") == 0) return CHARGE;
    if (strcmp(str, "ADD") == 0) return ADD;
    if (strcmp(str, "PSH") == 0) return PUSH;
    if (strcmp(str, "PUL") == 0) return PULL;
    if (strcmp(str, "HLT") == 0) return HALT;
    if (strcmp(str, "IFF") == 0) return IF;
    if (strcmp(str, "CPR") == 0) return CPR;
    if (strcmp(str, "JMP") == 0) return JMP;
    return HALT;
}

char* operand_to_string(Operand operand) {
    switch (operand) {
        case START:
            return "STT";
        case CHARGE:
            return "CHG";
        case ADD:
            return "ADD";
        case PUSH:
            return "PSH";
        case PULL:
            return "PUL";
        case HALT:
            return "HLT";
        case IF:
            return "IFF";
        case CPR:
            return "CPR";    
        case JMP:
            return "JMP";
    }
    return "UNDEFINED";
}

