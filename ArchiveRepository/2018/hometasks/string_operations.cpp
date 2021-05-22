#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

#include <algorithm>
vector<int> string_operations(vector<string> str_v, string &short_str, string &long_str,
                              string &first_str, string &last_str)
{
    vector<int> result_v(str_v.size());
    short_str = str_v[0];
    long_str = str_v[0];
    for(size_t i = 0; i < str_v.size(); ++i){
        result_v[i] = str_v[i].size();
        if(str_v[i].size() < short_str.size()) short_str = str_v[i];
        if(str_v[i].size() > long_str.size()) long_str = str_v[i];
    }
    sort(str_v.begin(), str_v.end());
    first_str = str_v[0];
    last_str = str_v[str_v.size() - 1];
    return result_v;
}
int main()
{
    vector<string> s_vect = {"One","Two","Free","Four"};
    vector<string> s_vect2 = {"That","cant","be","Finished"};
    string short_str, long_str, first_str, last_str;
    vector<int> i_vect = string_operations(s_vect2, short_str, long_str,first_str,last_str);


    return 0;

}





