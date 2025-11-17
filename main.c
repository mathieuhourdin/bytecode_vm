#include <stdlib.h>
#include <stdio.h>

#include "src/cpu.h"
#include "src/instruction.h"
#include "src/stack.h"
#include "src/program.h"



int main() {

    Program *program = program_parse("code.txt");
    program_dump(program);
    cpu_initialize();
    cpu_execute_code(program);
    free(program);
}




