#include <stdlib.h>

#include "register.h"

Register *my_register = NULL;

Register* register_new() {
    Register *new_register = malloc(sizeof(Register));
    new_register->rg1 = 0;
    new_register->rg2 = 0;
    return new_register;
}

