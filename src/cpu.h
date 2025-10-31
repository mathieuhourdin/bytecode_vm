#ifndef CPU_H
#define CPU_H

/**
 *
 * Here the cpu behaves like a stack which can contain and consume two values;
 *
 */
typedef struct Cpu {
    int rg1;
    int rg2;
} Cpu;

extern Cpu *cpu;

Cpu* cpu_new();
void cpu_add();
int cpu_register_get_last_value();
void cpu_register_charge(int value);

#endif
