#include <stdlib.h>

#include "cpu.h"

Cpu *cpu = NULL;

Cpu* cpu_new() {
    Cpu *new_cpu = malloc(sizeof(Cpu));
    new_cpu->rg1 = 0;
    new_cpu->rg2 = 0;
    return new_cpu;
}

void cpu_add() {
    cpu->rg2 += cpu->rg1;
}

void cpu_register_charge(int value) {
    cpu->rg1 = cpu->rg2;
    cpu->rg2 = value;
}

int cpu_register_get_last_value() {
    return cpu->rg2;
}

