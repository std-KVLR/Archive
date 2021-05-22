#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned x = 1000;
    int b;

    for(b = 0; x != 0; x &= (x-1), b++);
    printf("b = %d", b);
    return 0;
}
