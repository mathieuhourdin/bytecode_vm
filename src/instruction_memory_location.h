#ifndef INSTRUCTION_MEMORY_LOCATION_H
#define INSTRUCTION_MEMORY_LOCATION_H

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


MemoryLocation memory_location_from_string(char* string);
char* memory_location_to_string(MemoryLocation memory_location);

#endif
