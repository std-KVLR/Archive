#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void entab(char *s)
{
    const int tab_sp_size = 8;
    size_t strSize = strlen(s);
    int tab_count = strSize / tab_sp_size;

    *(s + (strSize - (tab_count * tab_sp_size))) = '\0';
    while(tab_count-- > 0) *s++ = '\t';
}

int main()
{
    char s[] = "          ";
    printf("%s|\n", s);
    entab(s);
    printf("%s|", s);
    return 0;
}
