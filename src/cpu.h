#ifndef CPU_H
#define CPU_H

typedef struct Instruction Instruction;
typedef struct Program Program;
typedef struct StackSegment StackSegment;
/**
 * The CPU can hold and manipulate two values in its registers, in RG1 and RG2.
 * RG1 is the only register directly related to the outside of the CPU.
 * When we charge a new value, pull from a stack memory address it goes in RG1.
 * And RG1 previous value is pushed in RG2.
 * RG1 is also the result address of all calculations performed on RG1 and RG2 (ADD, CPR..).
 * PUSH or IF actions use the value in RG1 to push to stack or to choose the next instruction.
 *
 * It holds a pointer to a Program (the currently executed program)
 * A pointer to an instruction, the instruction where we currently are in the program execution
 * A stacksegment on which it has ownership, the stacksegment used for the current program execution.
 *
 * CPU should always be in a valid state, that means that :
 *  - rg1 and rg2 are always valid integers.
 *  - rg1 is the result of the previous operation
 *  - If CPU has a program, code pointer should point to a valid instruction
 */
typedef struct Cpu {
    int acc; //the accumulator of the cpu
    int ret; //where the accumulator value is stored each time a new value is set in the accumulator. Something like retention ?
    Instruction *pc; //the usual term is pc program counter and not code pointer. It should be an int in the range of the program.
    Program *program;
    StackSegment *stacksegment; //we should choose if the memory belongs to the cpu or is managed separatedly and cpu just holds a reference.
} Cpu;

extern Cpu *cpu;

/**
 * Creates a new CPU instance.
 */
void cpu_initialize();

/**
 * Launch the execution of a whole program
 */
void cpu_execute_code(Program *program);

#endif
