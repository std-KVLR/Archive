#include <stdio.h>
#include <stdlib.h>
int ANY(char string1[], char string2[]);

int main()
{
    char s1[10], s2[10];


    gets(s1), gets(s2);
    printf("POSITION = %d", ANY(s1,s2));

return 0;
}


int ANY(char string1[], char string2[])
{
int there = 0, i, j;

    for(i = 0; string1[i] != '\0'; i++){
        for(j = 0; string2[j] != '\0';++j){
            if(string1[i] == string2[j]){
                there = ++i;
                break;}
        }
        if (there != 0) return there;
    }
   return -1;
 }
