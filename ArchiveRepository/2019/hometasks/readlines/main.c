#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000


int getline_ex(char *s, int lim);

int readlines(char *lineptr[], int maxlines, char *buffer, int buffSize)
{
    int len, nlines;
    char *p = buffer;
    char line[MAXLEN];
    nlines = 0;

    while ((len = getline_ex(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (buffSize - len) <= 0) return -1;
        else {
            line[len] = '\0'; /* удаление конца строки */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len + 1;
            buffSize -= len;
        }
    return nlines;
}
int main()
{
    char *lnptr[10];
    char *buffer[100] = {0};
    printf("%d",readlines(lnptr, 10, buffer, 10));
    printf("%s", lnptr[0]);
    printf("%s", lnptr[1]);
    printf("%s", lnptr[2]);
    return 0;
}


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
