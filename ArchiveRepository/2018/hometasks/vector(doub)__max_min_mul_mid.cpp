#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <vector>
#include <string>
#include "std_lib_facilities.h"
#include <cmath>
#include <limits.h>
#include <stdexcept>
using namespace std;


double price_weight_MUL(const vector<double> &price,const vector<double> &weight)
{
    if(weight.size() > price.size()) throw runtime_error("error:vector weight is greater than vector price.");

    double result = 0;
    for(size_t i = 0; i < weight.size(); ++i)
    {
        result += weight[i]*price[i];
    }
    return result;
}
double maxv(const vector<double> &work_v)
{
    double max_v = 0;
    for(size_t i = 0; i < work_v.size(); ++i)
    {
        if(work_v[i] > max_v) max_v = work_v[i];
    }
    return max_v;
}
double vector_calculate(const vector<double> &work_v, double &max_v, double &min_v, double &midian)
{
    double mid_value = 0;
    max_v = 0;
    min_v = 0;
    midian = 0;
    size_t i = 0;
    for(; i < work_v.size(); ++i)
    {
        if(work_v[i] > max_v) max_v = work_v[i];
        if(work_v[i] < min_v) min_v = work_v[i];
        mid_value += work_v[i];
    }
    cout << work_v.size() << '\n';
    cout << (work_v.size()/2) << '\n';
    midian = work_v[work_v.size()/2];
    return mid_value/i;
}
int main()
{
    vector<double> test_v;
    for(size_t i = 0; i < 10; ++i) test_v.push_back(i);
    double maximum, minimum, midian, middle = vector_calculate(test_v,
                                                               maximum,minimum,midian);
    vector<double> test_v2(10,2);
    cout << maximum << ' ' << minimum << ' '
         << midian << ' ' << middle;

    return 0;

}





