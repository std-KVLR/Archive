#include <stdio.h>
#include <stdlib.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
 unsigned int x = 50;
 printf("%d", x);
 x = setbits(x,6,3,100);
 printf("\n%d",x);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n))  << (p + 1 - n));
}

