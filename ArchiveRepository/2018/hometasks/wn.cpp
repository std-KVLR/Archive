#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>



using namespace std;
int main()
{
	//int work_arr[100];
	//for(short i = 0; i > 100; ++i)work_arr[i] = i + 1;
	char testC;

	for(size_t i = 1, lhor = 1, rhor = 100, sizeD; i != 7; i++ ){
        sizeD = (rhor - lhor) / 2;
        cout << "Value smaller then " << lhor + sizeD << "?(y or n)\n", cin >> testC;
	    if(testC == 'y') rhor = sizeD;
	    else if(testC == 'n') lhor = sizeD;
	}
	return 0;
}

