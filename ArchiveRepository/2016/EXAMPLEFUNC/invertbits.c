#include <stdio.h>

unsigned invertbit(x, p, n);

int main()
{
    unsigned x = 240;


    printf("%d",  invertbit(x, 7, 4));

    return 0;

}

unsigned invertbit(x, p, n)
{
    return (x & (~(~0 << p + 1 - n))) | ((x ^ ~(~0 << p + 1)) & (~0 << p + 1 - n));
}
