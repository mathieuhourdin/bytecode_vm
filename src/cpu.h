#ifndef CPU_H
#define CPU_H

typedef struct Instruction Instruction;
typedef struct Code Code;
/**
 *
 * Here the cpu behaves like a stack which can contain and consume two values;
 *
 */
typedef struct Cpu {
    int rg1;
    int rg2;
    Instruction *code_pointer;
} Cpu;

extern Cpu *cpu;

void cpu_initialize();
void cpu_execute_code(Code *code);

#endif
