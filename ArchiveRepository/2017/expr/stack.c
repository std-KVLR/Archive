#include "stack.h"


int push(double value)
{
    if(stk_size == 0) return -1;
    *stk_pointer++ = value;
    --stk_size;
    return stk_size;
}
int pop(double* value)
{
    if(stk_size == STACKSIZE) return -1;
    *value = *--stk_pointer;
    ++stk_size;
    return stk_size;
}


