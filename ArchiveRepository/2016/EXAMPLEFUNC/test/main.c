#include <stdio.h>



int main()
{

char s[10];
int c;
int i, j ;

fgets(s,10,stdin);
c = 'I';

for (i = j =0; s[i] != '\0'; i++)
    if (s[i] != c){s[j++] = s[i];}
s[j] = '\0';


return 0;
}
