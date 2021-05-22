#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(x,n)
{
    int i = 0;
    unsigned result = x;
    while(i++< n){
        if((result & 1) == 0)result = result >> 1;
        else result = ((result >> 1) | (~(~0u >> 1)));
    }
    return result;
}

unsigned rightrotbestversion (x, n)
{
   return (x >> n) | ((x & ~(~0 << n)) << (sizeof(x)* 8) - n);
}

int main()
{
    unsigned x = 10 ;
    unsigned n = 5;
    x = rightrotv2(x,n);
    printf("x = %u\n", x);
    return 0;
}
