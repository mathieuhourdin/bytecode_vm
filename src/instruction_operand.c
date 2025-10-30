#include <string.h>

#include "instruction_operand.h"

Operand operand_from_string(char* str) {
    if (strcmp(str, "START") == 0) return START;
    if (strcmp(str, "CHARGE") == 0) return CHARGE;
    if (strcmp(str, "ADD") == 0) return ADD;
    if (strcmp(str, "PUSH") == 0) return PUSH;
    if (strcmp(str, "PULL") == 0) return PULL;
    if (strcmp(str, "HALT") == 0) return HALT;
    return HALT;
}

char* operand_to_string(Operand operand) {
    switch (operand) {
        case START:
            return "START";
        case CHARGE:
            return "CHARGE";
        case ADD:
            return "ADD";
        case PUSH:
            return "PUSH";
        case PULL:
            return "PULL";
        case HALT:
            return "HALT";
    }
    return "UNDEFINED";
}

