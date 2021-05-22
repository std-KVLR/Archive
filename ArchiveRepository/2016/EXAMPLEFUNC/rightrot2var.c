#include <stdio.h>
#include <limits.h>
unsigned rightrotcycle(x, n);
unsigned rightrot(x, n);
int main()
{
   unsigned x = 134;
   int y;

    printf("%d", rightrot(x, 4));

    return 0;

}
                           
unsigned rightrot (x, n)
{
   return (x >> n) | ((x & ~(~0 << n)) << (sizeof(x)* 8) - n);
}




unsigned rightrotcycle(x, n)
{
   while( n-- > 0){
        if(x & 1) x = (x >> 1) | ~(~0u >> 1);
        else x = (x >> 1) & (~0u >> 1);
   }
   return x;
}

