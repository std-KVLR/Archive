#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void reverse_ts(char *s)
{
    char *p = s + (strlen(s) - 1);

    do{
        *s = *s + *p;
        *p = *s - *p;
        *s = *s - *p;
    }while(--p != ++s);
}

void itoa_ts(char *s, int number)
{
    char *p = s;
    do{
        *s++ = (number % 10) + '0';
    }while(number /= 10);
    *s = '\0';
    reverse_ts(p);
}



int main()
{
    char array[10] = {0};
    int i = 12345;
    itoa_ts(array, i);
    printf("%s", array);
}
















void itoaMV(int n, char s[], int maxline)
{
    int i = 0;
    int sign = n;

    do {
        if(n !=0)s[i++] = abs(n) % 10 + '0';
        else s[i++] = ' ';
        n /= 10;
    } while (i < maxline );

    if (sign < 0) s[i++] ='-';
    s[i] ='\0';
    reverse_ts(s);

}

void itob(int number, char *workstr, int systNot)
{
    int i = 0;
    int sign = number;
    int hexcalc;

    switch(systNot)
    {
    case 2:
        do{
            if((number % 2) != 0)workstr[i++] = '1';
            else workstr[i++] = '0';
        }while( number != -1 && (number = number >> 1) != 0 );
        printf("Binary system.\n");
        break;
    case 10:
        do {
            workstr[i++] = abs(number) % 10 + '0';
        } while ((number /= 10) != 0);
        if (sign < 0) workstr[i++] ='-';
        printf("Decimal system.\n");
        break;
    case 16:
        do{
            hexcalc = abs(number - (number/16)*16);
            if(hexcalc < 10) workstr[i++] =  hexcalc + '0';
            else workstr[i++] = (hexcalc + 'A') - 10;
        }while( (number /= 16) != 0);
        printf("Hexadecimal system.\n");
        break;
    default:
        printf("Incorrect Arguments.\n");
        break;
    }
    workstr[i] = '\0';
    reverse_ts(workstr);
}
