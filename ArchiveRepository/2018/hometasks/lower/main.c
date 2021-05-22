#include <stdio.h>
#include <stdlib.h>

int lower (int c)
{
    int result = c;
    result = (c >= 'A' && c <= 'Z') ?  c + 'a' - 'A': c;
    return result;
}

int main()
{
    int c;
    while((c = getchar())!= EOF){
        printf("upper = %c\n", c);
        c = lower(c);
        printf("lower = %c\n", c);
        fflush(stdin);
    }
    return 0;
}
