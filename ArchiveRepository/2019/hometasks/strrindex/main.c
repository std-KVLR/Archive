#include <stdio.h>
#include <stdlib.h>


int strrindex (char *s, char *t)
{
    int i,j,k;
    int tmp = -1;

    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++); // NOP
        if(k > 0 && t[k] == '\0') tmp = j - 1;
    }
    return tmp;
}

int strrindex_p (char *s, char *t)
{
    char *ps = s;
    char *pt = t;
    int tmp = -1;

    while(*s  != '\0'){
        for(ps = s, t = pt; *t != '\0' && *s == *t;++s, ++t);
        if(t > pt && *t == '\0') tmp = (s - ps) - 1;
        s = ++ps;
    }
    return tmp;
}
int main()
{
    char s1[] = "InugamiDimas";
    char s2[] = "Dimas";


    printf("%d", strrindex_p(s1,s2));
    return 0;
}
