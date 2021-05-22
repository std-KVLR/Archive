#include <stdio.h>
#include <stdlib.h>
int HTOI(char str[]);
int main()
{
    char s[10];
    int n;

    gets(s), printf("%d", n = HTOI(s));

    return 0;
}

int HTOI(char str[])
{
    int i;
    int HEX = 0;

    for (i = 0; (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F');++i){
       switch(str[i]){
        case '0':
            if (str[i+1] == 'x' || str[i+1] == 'X'){
                    ++i;
                    break;}
        default:
            if(str[i] >= '0' && str[i] <= '9') HEX = 16*HEX + (str[i] - '0');
            else{if(str[i] >= 'A' && str[i] <= 'F') HEX = 16*HEX +((str[i] - 'A') + 10);}
            break;
        }
    }
    return HEX;
}
