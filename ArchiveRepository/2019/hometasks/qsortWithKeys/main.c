#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXSIZE 5000
char* lineptr[MAXLINES];
char buffer[MAXSIZE];

int readlines(char *lineptr[], int maxlines, char *buffer, int buffSize);
void writelines(char* lineptr[], int nlines);

void qsort_m(void* v[], int left, int right,
           int (*comp)(void*, void*, unsigned char), unsigned char);

int numcmp(char*, char*, unsigned char key);
int strcmp_m(char*, char*, unsigned char key);
void reverse_ts(void *s[], void *e[]);




int main(int argc, char *argv[])
{
    int nlines;
    unsigned char dfrn = 0;

    while(argc-- > 1 && (*++argv)[0] == '-'){
        switch(*++argv[0]){
        case 'n': dfrn |= 1; break;
        case 'r': dfrn |= 2; break;
        case 'f': dfrn |= 4; break;
        case 'd': dfrn |= 8; break;
        }
    }
        if((nlines = readlines(lineptr, MAXLINES, buffer, MAXSIZE)) >= 0){

             qsort_m((void**)lineptr,0, nlines - 1,(int (*)(void*,void*, unsigned char))
                     ((dfrn & 1) ? numcmp : strcmp_m), dfrn);
             if(dfrn & 2) reverse_ts((void**)lineptr, (void**)lineptr + (nlines -1));
             writelines(lineptr,nlines);
            return 0;
    }
    else{
        printf("input too big to sort\n");
        return 1;
    }
}


void qsort_m(void* v[], int left, int right,
           int (*comp)(void*, void*, unsigned char), unsigned char key)
{
    int i, last;
    void swap(void *v[], int i, int j);

    if(left >= right) return;

    swap(v, left, (left + right) /2);
    last = left;

    for(i = left + 1; i <= right; ++i){
        if((*comp)(v[i], v[left], key) < 0)
            swap(v, ++last, i);
    }
    swap(v,left,last);
    qsort_m(v, left, last - 1, comp, key);
    qsort_m(v, left + 1, last, comp, key);
}




void writelines(char* lineptr[], int nlines)
{
    while(nlines-- > 0){
            printf("%s\n", *lineptr++);
    }
}


void swap(void* v[], int i, int j)
{
    void* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
#define factorCount(x) ((x >= 97) ? x - factorAlpha : x)

int strcmp_m(char *s1, char *s2, unsigned char key)
{
    unsigned char factorAlpha = 0, factorSymb = 0;

    if(key & 4) factorAlpha = 32;
    if(key & 8) factorSymb = 1;

    while(*s1 != '\0' && *s2 != '\0'){
            if(factorSymb){
                if(!(isalnum(*s1) || *s1 == ' ')){
                         ++s1;
                         continue;
                }
                if(!(isalnum(*s2) || *s2 == ' ')){
                        ++s2;
                        continue;
                }
            }
            if(factorCount(*s1) != factorCount(*s2)) break;
            ++s1, ++s2;
    }
    if(factorCount(*s1) > factorCount(*s2)) return 1;
    else if(factorCount(*s1) < factorCount(*s2)) return -1;
    else return 0;
}
int numcmp(char *s1, char *s2, unsigned char key)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
}




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

void reverse_ts(void *s[], void *e[])
{
    void *temp = *s;

    do{
        temp = *s;
        *s = *e;
        *e = temp;
    }while(--e > ++s);
}
