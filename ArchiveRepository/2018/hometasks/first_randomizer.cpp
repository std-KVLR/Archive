#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <vector>
#include <string>
#include "std_lib_facilities.h"
#include <cmath>
#include <limits.h>
using namespace std;


size_t my_randomizer(const int &seed_arg = NULL)
{
    static unsigned long seed = 1;
    const int m = INT_MAX;
    const int a = 9301;
    const int c = 49297;
    if(seed_arg != 0) seed = seed_arg;

    seed = (seed * a + c) % m;
    return (size_t) seed;
}
size_t my_randint(const int &min_val, const int &max_val)
{
    return min_val + (my_randomizer()) % max_val;
}

int main()
{
    vector<double> test_v(10,0);

    return 0;

}



