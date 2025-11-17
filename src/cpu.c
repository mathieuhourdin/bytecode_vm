#include <stdlib.h>
#include <stdio.h>

#include "cpu.h"
#include "instruction.h"
#include "stack.h"
#include "program.h"

Cpu *cpu = NULL;

Cpu* cpu_new() {
    Cpu *new_cpu = malloc(sizeof(Cpu));
    new_cpu->acc = 0;
    new_cpu->ret = 0;
    new_cpu->pc = NULL;
    new_cpu->program = NULL;
    new_cpu->stacksegment = NULL;
    return new_cpu;
}

void cpu_dump(const Cpu *cpu) {
    instruction_dump(cpu->pc);
    printf("Acc : %i\n", cpu->acc);
    printf("Ret : %i\n", cpu->ret);
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
    int ret = cpu->ret;
    cpu->acc += cpu->ret;
    cpu->ret = ret;
}

void cpu_compare() {
    cpu->acc = cpu->acc > cpu->ret;
}

void cpu_if() {
    if (cpu->acc) {
        cpu->pc += 1;
    } else {
        cpu->pc += 2;
    }
}

void cpu_jump(int value) {
    cpu->pc = &cpu->program->instructions[value - 1];
}

void cpu_register_charge(int value) {
    cpu->ret = cpu->acc;
    cpu->acc = value;
}

int cpu_register_get_acc() {
    return cpu->acc;
}

/**
 * Main method of the CPU, which updates the state of the CPU based on rules for interpretation of each instruction.
 */
void cpu_execute_instruction() {
    cpu_dump(cpu);
    Instruction *instruction = cpu->pc;
    switch (instruction->operand) {
        case START:
            cpu->stacksegment = stacksegment_new();
            break;
        case CHARGE:
            cpu_register_charge(instruction->value);
            break;
        case ADD:
            cpu_add();
            break;
        case PUSH:
            int value = cpu_register_get_acc();
            stacksegment_push(cpu->stacksegment, value, instruction->destination);
            break;
        case PULL:
            int pull_value = stacksegment_pull(cpu->stacksegment, instruction->destination);
            cpu_register_charge(pull_value);
            break;
        case CPR:
            cpu_compare();
            break;
        case IF:
            cpu_if();
            return;
        case JMP:
            cpu_jump(instruction->value);
            return;
        case HALT:
            printf("Result of the program : %d\n", cpu_register_get_acc());
            cpu->program = NULL;
            free(cpu->stacksegment);
            cpu->stacksegment = NULL;
            return;
    }
    cpu->pc = instruction + 1;
}

/**
 *
 * @brief launch the execution of a given program;
 *
 * To be valid, a program should start with a START instruction and end with a HALT instruction.
 *
 */
void cpu_execute_code(Program *program) {
    cpu->program = program;
    cpu->pc = program->instructions;
    while (cpu->pc->operand != HALT) {
        printf("Instruction : %p\n", cpu->pc);
        cpu_execute_instruction();
    }
    cpu_execute_instruction();
}

