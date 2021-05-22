#include <stdio.h>
#include <stdlib.h>





int htoi(char s[])
{
	int result = 0, i;

		for (i = 0; s[i] != '\0'; i++ ){

			if((s[i] >= '1' && s[i] <= '9')){

				result = result * 16 + (s[i] - '0');
			}
			else if (s[i] >= 'A' && s[i] <= 'F'){

				result = result * 16 + (s[i] - '7');
			}
			else if(s[i] == '0' || s[i] == 'x' || s[i] == 'X');
			else puts("Error in string"), exit(0);
		}
	return result;
}

int main()
{
	char s[10];
	int i;

		s[0] = '0';
		s[1] = 'x';
		s[2] = 'A';
		s[3] = 'B';
		s[4] = '9';
		s[5] = 'C';
		s[6] = '\0';
	i = htoi(s);
	printf("%x", i);
return 0;
}
