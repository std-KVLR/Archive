#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#define STACKSIZE 50


static double arg_stack[STACKSIZE];
static double* stk_pointer = arg_stack;
static size_t stk_size = STACKSIZE;

int push(double value);
int pop(double* value);


#endif // STACK_H
