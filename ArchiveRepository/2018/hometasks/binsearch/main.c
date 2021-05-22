#include <stdio.h>
#include <stdlib.h>


int binsearchv1(int Search_Number, int DataBuffer[], int MaxRange)
{
    int low, high, mid;

    low = 0;
    high = MaxRange- 1;
    while(low <= high){
        mid = (low+high)/2;
        if(Search_Number < DataBuffer[mid]) high = --mid;
        else if (Search_Number > DataBuffer[mid]) low = ++mid;
        else return mid;
    }
    return -1;
}

int binsearchv2(int Search_Number, int DataBuffer[], int MaxRange)
{
    int low, high, mid;

    low = 0;
    high = MaxRange- 1;

    while(low <= high && Search_Number != DataBuffer[mid]){
        mid = (low+high)/2;
        if(Search_Number < DataBuffer[mid]) high = --mid;
        else low = ++mid;
    }
    if(Search_Number == DataBuffer[mid]) return mid;
    return -1;
}



int main()
{
    int x = 8, v[50] = {0,1,2,3,4,5,6,7,8,9,11}, result = 0;

    printf("Result = %d\n",result = binsearchv1(x,v, 10));



    return 0;
}
