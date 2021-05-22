#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GetDynamicLine(char **DynamicString);
void ExpandWC(int min, int max);
void Expand(char *s1, char *s2);


int main()
{
    char *s1;
    char s2[50] = {0};

        if(GetDynamicLine(&s1) == 1) return 1;
        Expand(s1, s2);
        printf("S1 = %s\nS2 = %s \n", s1, s2);
        free(s1);

    return 0;
}


void Expand (char *s1, char *s2)
{
    char xyzBuffer[26] = {0};
    int i, j, dif, strpoint;

        for(i = 0, strpoint = 0; s1[i] != '\0'; i++){
            if(s1[i] == '-' && (s1[i+1] - s1[i-1]) > 0 &&
            (s1[i-2] == 32 || i-1 == 0) && (s1[i+2] == 32 || s1[i+2] == '\0' )){
                    if((s1[i-1] > 47 && s1[i-1] < 58 && s1[i+1] > 47 && s1[i-1] < 58) ||
                       (s1[i-1] > 64 && s1[i-1] < 91 && s1[i+1] > 64 && s1[i-1] < 91) ||
                       (s1[i-1] > 96 && s1[i-1] < 123 && s1[i+1] > 96 && s1[i-1] < 123)){ //is digit
                            for(j = 0, dif = s1[i-1] + 1; dif < s1[i+1]; j++, dif++){
                                xyzBuffer[j] = dif;
                            }
                            strcpy(s2+strpoint, xyzBuffer);
                            strpoint += j;
                            memset(xyzBuffer, '\0', 26);
                    }
            }
            else s2[strpoint++] = s1[i];
       }
}

int GetDynamicLine(char **DynamicString)   // unsafe(manual memory control)
{
    char WorkBuffer[10] = {0};
    int size = 0;

    if((*DynamicString = (char*) calloc( 10, sizeof(char)))== NULL){
        printf("Memory Allocation Error.");
        return 1;
    }

    while(DynamicString[0][size - 1] != '\n' && WorkBuffer[0] != '\n'){
        fgets(WorkBuffer, 10 , stdin);
        if(DynamicString[0][0] != '\0'){
              if((*DynamicString = (char*) realloc(*DynamicString, (strlen(WorkBuffer) + (size + 1)) * sizeof(char)))== NULL){
                  printf("Memory Allocation Error.");
                  return 1;
              }
        }

        strcat(&(*DynamicString)[size],WorkBuffer);
        size = strlen(*DynamicString);
    }
    if(WorkBuffer[0] != '\n') DynamicString[0][--size] =  0;
    return 0;
}
