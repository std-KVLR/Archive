#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


double atofMYV(char *s)
{
    double val, power, result;
    int i, sign;

    for(i = 0;isspace(s[i]);i++);
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') i++;
    for (val = 0.0; isdigit(s[i]);i++){
        val = 10.0 * val + (s[i] - '0');
    }
    if(s[i] == '.') i++;
    for (power = 1.0; isdigit(s[i]);i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    result = sign*val/power;
    if(s[i] == 'E' || s[i++] == 'e'){
        s[i++] == '-'? sign = -1 : sign == 1;
        result *= pow(10, sign*(int)(s[i] - '0'));
    }
    return result;
}
int main()
{
    char *s = "143.15e-6";
    atofMYV(s);
    printf("Hello world!\n");
    return 0;
}
