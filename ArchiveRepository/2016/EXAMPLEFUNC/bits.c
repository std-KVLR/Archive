#include <stdio.h>

unsigned invertbit(x, p, n);

int main()
{
    unsigned x = 85;


    printf("%d",  invertbit(x, 7, 4));

}

unsigned invertbit(x, p, n)
{
    return (x & (~(~0 << (p + 1 - n)))) | (x & (~0 << p + 1 - n));
}
