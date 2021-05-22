#include <iostream>
#include <vector>
#include <memory>
#include <list>
//#include <fltk.h>
using namespace std;

int i[] = {0,1,2,3,4,5,6,7,8,9};
vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
list<int> li = {0,1,2,3,4,5,6,7,8,9};

int *i2 = i;
vector<int> vi2 = vi;
list<int> li2 = li;

void increase(int* start, size_t num, int val)
{
        for(int j = 0; j < num; ++j)start[j] += val;

}

void func(int **arr)
{

}

int main()
{
    int arrr[50];
    func(&arrr);
    for(int j = 0; j < 10; ++j) cout << i[j] << ' ';
    cout << endl;
    increase(i, 10, 2);
    for(int j = 0; j < 10; ++j) cout << i[j] << ' ';
    cout << endl;
    increase(i, 10, 3);
    for(int j = 0; j < 10; ++j) cout << i[j] << ' ';
    cout << endl;
    increase(i, 10, 5);
    for(int j = 0; j < 10; ++j) cout << i[j] << ' ';
    return 0;
}
