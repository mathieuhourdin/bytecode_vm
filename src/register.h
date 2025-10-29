#ifndef REGISTER_H
#define REGISTER_H

/**
 *
 * Here the register behaves like a stack which can contain and consume two values;
 *
 */
typedef struct Register {
    int rg1;
    int rg2;
} Register;

extern Register *my_register;

Register* register_new();
void register_add();
int register_get_last_value();
void register_charge(int value);

#endif
