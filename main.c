#include <stdlib.h>
#include <stdio.h>

#include "src/cpu.h"
#include "src/instruction.h"
#include "src/stack.h"



int main() {

    Code *code = code_parse("code.txt");
    code_dump(code);
    code_execute(code);
    free(code);
}




