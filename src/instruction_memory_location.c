#include <stdlib.h>
#include <string.h>

#include "instruction_memory_location.h"

MemoryLocation memory_location_from_string(char* string) {
    if (strcmp(string, "STACK_0") == 0) return STACK_0;
    if (strcmp(string, "STACK_1") == 0) return STACK_1;
    if (strcmp(string, "STACK_2") == 0) return STACK_2;
    if (strcmp(string, "STACK_3") == 0) return STACK_3;
    if (strcmp(string, "STACK_4") == 0) return STACK_4;
    if (strcmp(string, "STACK_5") == 0) return STACK_5;
    if (strcmp(string, "STACK_6") == 0) return STACK_6;
    if (strcmp(string, "STACK_7") == 0) return STACK_7;
    if (strcmp(string, "STACK_8") == 0) return STACK_8;
    if (strcmp(string, "STACK_9") == 0) return STACK_9;
    return STACK_0;
}

char* memory_location_to_string(MemoryLocation memory_location) {
    switch (memory_location) {
        case STACK_0:
            return "STACK_0";
        case STACK_1:
            return "STACK_1";
        case STACK_2:
            return "STACK_2";
        case STACK_3:
            return "STACK_3";
        case STACK_4:
            return "STACK_4";
        case STACK_5:
            return "STACK_5";
        case STACK_6:
            return "STACK_6";
        case STACK_7:
            return "STACK_7";
        case STACK_8:
            return "STACK_8";
        case STACK_9:
            return "STACK_9";
        case NO_LOCATION:
            return "NO_LOCATION";
    }
    return "UNKNOWN";
}

