#include <stdlib.h>

#include "register.h"

Register *my_register = NULL;

Register* register_new() {
    Register *new_register = malloc(sizeof(Register));
    new_register->rg1 = 0;
    new_register->rg2 = 0;
    return new_register;
}

void register_add() {
    my_register->rg2 += my_register->rg1;
}

void register_charge(int value) {
    my_register->rg1 = my_register->rg2;
    my_register->rg2 = value;
}

int register_get_last_value() {
    return my_register->rg2;
}

