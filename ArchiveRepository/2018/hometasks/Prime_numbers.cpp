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
#include<stdlib.h>

using namespace std;

vector <int> prime_numbers(const size_t &max_n, const size_t &n );
void prime_numbers_for_max(vector <int> &numbers_v, const size_t &max_n);
vector <int> prime_numbers_for_n(const size_t &n);

int main()
{
    vector <int> my_v = prime_numbers(0, 15);
    for(const auto &i : my_v) cout << i << ' ';

    return 0;
}

vector <int> prime_numbers(const size_t &max_n, const size_t &n)
{

    if(max_n < 2 && n == 0){

    }
    vector <int> result_v;
    if(n == 0 && max_n >= 2){
            vector <int> numbers_v(max_n + 1);
            for(size_t i = 2, endv = numbers_v.size(); i < endv; ++i) numbers_v[i] = 1;
            numbers_v[0] = 0, numbers_v[1] = 0;
            prime_numbers_for_max(numbers_v, max_n);
            for(size_t i = 2, endv = numbers_v.size(); i < endv; ++i){
                if(numbers_v[i] == 1) result_v.push_back(i);
            }
    }
    else if(n != 0 && max_n < 2) result_v = prime_numbers_for_n(n);
    else {cerr << "Error. Invalid arguments\n"; throw(-1);}
    return result_v;
}

void prime_numbers_for_max(vector <int> &numbers_v, const size_t &max_n)
{
     cout << "Searching prime numbers 1..." << max_n << '\n';
        for(size_t i = 2, end_f = sqrt(max_n); i <= end_f; ++i){
            if(numbers_v[i] == 1){
                for(size_t j = i * i, endv = numbers_v.size(); j < endv; ++j){
                        if((j % i) == 0) numbers_v[j] = 0;
                }
            }
        }
}

vector <int> prime_numbers_for_n(const size_t &n)
{
    cout << "Searching first " << n << " prime numbers\n";

    vector <int> numbers_f_n(1,2);

    for(size_t i = 3, counter = 1; counter != n; ++i){
        for(size_t j = 0, end_v = numbers_f_n.size() - 1;;++j){
            if((i % numbers_f_n[j]) == 0) break;
            if(j == end_v){
                numbers_f_n.push_back(i);
                ++counter;
                break;
            }
        }
    }
    return numbers_f_n;
}
