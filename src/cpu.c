#include <stdlib.h>
#include <stdio.h>

#include "cpu.h"
#include "instruction.h"
#include "stack.h"

Cpu *cpu = NULL;

Cpu* cpu_new() {
    Cpu *new_cpu = malloc(sizeof(Cpu));
    new_cpu->rg1 = 0;
    new_cpu->rg2 = 0;
    new_cpu->code_pointer = NULL;
    return new_cpu;
}

void cpu_initialize() {
    cpu = cpu_new();
}

/**
 *
 * design thinking about the add instruction.
 *
 * The add instruction supposes that we have two integer values defined somewhere that we add.
 * And a place where the result is stored for future output (we should have different step for add and for store at this place);
 * In a hardware point of view, the two int values are put in a register in the cpu, related to the ADD electric circuit.
 * And some other register receives the output value of the addition.
 *
 */
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

void cpu_execute_instruction() {
    Instruction *instruction = cpu->code_pointer;
    switch (instruction->operand) {
        case START:
            stacksegment = stacksegment_new();
            break;
        case CHARGE:
            cpu_register_charge(instruction->value);
            break;
        case ADD:
            cpu_add();
            break;
        case PUSH:
            int value = cpu_register_get_last_value();
            stacksegment_push(value, instruction->destination);
            break;
        case PULL:
            int pull_value = stacksegment_pull(instruction->destination);
            cpu_register_charge(pull_value);
            break;
        case HALT:
            printf("Result of the program : %d\n", cpu_register_get_last_value());
            return;
    }
    cpu->code_pointer = instruction->next;
}

/**
 *
 * @brief launch the execution of a given program;
 *
 * To be valid, a program should start with a START instruction and end with a HALT instruction.
 *
 */
void cpu_execute_code(Code *code) {
    if (code->first_instruction == NULL || code->first_instruction->operand != START) {
        return;
    }
    cpu->code_pointer = code->first_instruction;
    while (cpu->code_pointer->operand != HALT) {
        printf("Instruction : %p\n", cpu->code_pointer);
        cpu_execute_instruction();
    }
    cpu_execute_instruction();
}
