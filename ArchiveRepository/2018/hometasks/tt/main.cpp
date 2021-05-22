#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cmath>
using namespace std;
string convert(const &string str)
{
    string result;

    for(size_t i = 2, j = 0; i < str.size() - 1; ++i, ++j){
        result[j] = str[i];
    }
    return result;
}

int main()
{
    ifstream ist("res.txt");
    char eat_buff[50] = {0};
    vector<string> digits;
    double temp;
    string int_str;
    string mod_str;
    while(ist >> temp){
        digits.push_back((int)temp);
        temp_str
        digits.push
        mods.push_back(modf(temp, &temp) * 100);
        ist.getline(eat_buff,50);
    }
    ofstream ost("res_filtr.txt");
    for(size_t i = 0; i < integers.size() - 1; ++i){
            ost << integers[i] << ','
                << mods[i] << '\n';
    }
    return 0;
}
