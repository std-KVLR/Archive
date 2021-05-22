#include <iostream>
#include <vector>
#include <string>
#include <fstream>



using namespace std;

int main()
{
    ifstream ist("INPUT.txt");
    vector<string> work_v;
    string temp;

    while(getline(ist,temp, ';')){
            ist.get();
            work_v.push_back(temp);

    }

    for(auto &s : work_v) cout << s << '\n';
    for(size_t i = 0 ; i != work_v.size() - 2; ++i){
        for(size_t j = i + 1; j != work_v.size() - 1; ++j){
            if(work_v[i] == work_v[j]){
                cout << i << '=' << j << endl;
                return 1;
            }
        }
    }
    cout << "OK" << endl;
    return 0;
}
