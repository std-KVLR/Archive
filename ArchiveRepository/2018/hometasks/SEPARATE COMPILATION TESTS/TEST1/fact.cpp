#include "Chapter6Test.h"
int exs6_3fact(int x)
{
    if(x != 1) return x * exs6_3fact(x - 1);
    return x;
}
