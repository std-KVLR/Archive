#include <stdio.h>
#include <stdlib.h>
void squeze(char str1[],char str2[]);
int main()
{
 int i,k;
 char s1[10], s2[10];

    gets(s1),gets(s2), puts(s1), puts(s2);
    return 0;
}

void squeze(char str1[],char str2[])
{
    int i, j;

        for (i = j = 0; s1[i] != '\0';i++){
            if(s1[i] == s2[j++])s1[i] = '\0', j = -1;
            if(s2[j] == '\0') j = -1;
        }
}
