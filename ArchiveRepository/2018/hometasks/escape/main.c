#include <stdio.h>
#include <stdlib.h>

void escape(char In[], char Out[])
{
    int i, j;

    for(i = j = 0; In[i] != '\0'; i++, j++){
        switch(In[i]){
    case '\t':
          Out[j] = 92;
          Out[++j] = 't';
          break;
    case '\n':
          Out[j] = 92;
          Out[++j] = 'n';
          break;
    default:
          Out[j] = In[i];
          break;
        }
    }
}

void unescape(char In[], char Out[])
{
      int i, j;

    for(i = j = 0; In[i] != '\0'; i++, j++){
        if(In[j] == '\\'){
                switch(In[j+1]){
            case 't':
                Out[i] = '\t';
                break;
            case 'n':
                Out[i] = '\n';
                break;
            default:
                Out[i] = In[j];
                break;
                }
                j++;
        }
        else Out[i] = In[j];
    }
}





int main()
{
    char len[20] = "a\tlolPUT\nI\tN";
    char olen[25] = {0};
    escape(len, olen);
    printf("DEF = %s\n OUT = %s\n", len, olen);
    unescape(olen, len);
    printf("OUTUN = %s\n",len);

    return 0;
}
