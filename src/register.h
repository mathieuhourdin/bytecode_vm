#ifndef REGISTER_H
#define REGISTER_H


typedef struct Register {
    int rg1;
    int rg2;
} Register;

extern Register *my_register;

Register* register_new();

#endif
