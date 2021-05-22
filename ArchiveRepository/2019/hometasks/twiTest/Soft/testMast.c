#include <stdio.h>

int main()
{
	int a = 59500;

	short a1 = a >> 8;
	short a2 = a & 255;	
	int a3 = a1 << 8;
	int a4 = a3 | a2;
	printf("%d\n", a1);
	printf("%d\n", a2);	
        printf("%d\n", a3);
	printf("%d\n", a4);
	return 0;
}
