#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *SearchString, *OperationString;

int GetDynamicLine(char **DynamicString)   // unsafe(manual memory control)
    {
    // char *pointer = &*DynamicString;
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
    printf("Output: %s\n", *DynamicString);
    return 0;
}

int any(char SearchString[], char OperationString[])
{
    int i,j;

        for(i = 0; SearchString[i] != '\0'; i++){
            for(j = 0; OperationString[j] != '\0' ;j++){
                if(SearchString[i] == OperationString[j]) return i + 1;
            }
        }
    return -1;
}

int main()
{
    int position;

    printf("Enter 1st String: ");
    if((GetDynamicLine(&SearchString)) == 1) return 1;
    printf("Enter 2nd String: ");
    if((GetDynamicLine(&OperationString)) == 1) return 1;

    position = any(SearchString, OperationString);
    if(position > 0) printf("First character position %d", position);
    else printf("The same symbols are not found");
    free(SearchString);
    free(OperationString);
    return 0;

}
