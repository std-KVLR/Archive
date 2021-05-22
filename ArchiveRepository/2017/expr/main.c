#include <stdio.h>



int main(int argc, char* argv[])
{

    while(--argc > 0){
        calculator((*++argv));
    }
    return 0;
}
