#include <stdio.h>
#include <stdlib.h>

void input_processing(void);

void wANDOR(int lim,char s[])
{
	int i;
	char c;
                 input_processing();
		 for( i = 0; i = (lim - 1); ++i){
	         c = getchar();
       		 if( c == '\n') break;
       	         else if( c == EOF) break;
    		 s[i] = c;
    		 printf("%c", s[i]);
   		 }
}

void input_processing (void)
{
int c;

while (c = getchar(), c != EOF && c >=' ' || c == '\t'){;}
}

int main()
{
    int lim = 0;
    char *s;

    puts("Enter number of characters:"), scanf("%d", &lim);
    s = (char*) calloc(lim, sizeof(char));

    wANDOR(lim,s);
    free(s);

    printf("\n");
    printf("EXIT");
    getchar();
    return 0;
}
