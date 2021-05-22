#include <stdio.h>
#include <stdlib.h>

int getline_ex(char *s, int lim)
{
    char* p = s;
    --lim;
    while(lim-- > 0 && (*s = getchar()) != EOF  && *s != '\n') ++s;
    if(*s == '\n' && lim > 0){
            *++s = '\0';
    }
    else *s == '\0';
    return (s - p) - 1;
}
