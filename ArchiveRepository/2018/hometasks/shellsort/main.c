#include <stdio.h>
#include <stdlib.h>

void OutputBuf (int v[])
{
    int i;
    for (i = 0; i < 15;i++){
    printf("%d, ", v[i]);
    }
}

void shellsort(int v[], int n)
{
    int gap, i, j, k, temp;

    for (gap = n/2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
            for (j = i-gap; j>=0 && v[j] > v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
                puts("Debug:");
                OutputBuf(v);
                putchar('\n');
            }
        }
    }
}
int main()
{
    int i;
    int v[15] = {2,99,32,47,76,86,10,9,75,93,11,71,56,40,6};
    int n = 15;
    printf("Begin:");
    OutputBuf(v);
    putchar('\n');
    shellsort(v, n);
    printf("End:");
    OutputBuf(v);
    return 0;
}
