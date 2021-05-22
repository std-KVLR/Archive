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
const vector <string> nouns = {"birds", "fish", "C++"};
const vector <string> verbs = {"rules", "fly", "swim"};
const vector <string> unions = {"and", "or", "but"};

string get()
{
    string str;
    cin >> str;
    if(!cin.good()) {cout << "Program exit."; exit(0);}
    if(str != "." && getchar() == '\n') throw runtime_error("No\n");
    return str;
}
int check(const string &word, const vector <string> &listt)
{
    for(size_t i = 0; i < listt.size(); ++i)
    {
        if(word == listt[i]) return 1;
    }
    return 0;
}
string collocation()
{
    string result;
    string temp = get();
    if(check(temp,nouns)) result += temp + " ";
    else throw runtime_error("No\n");
    temp = get();
    if(check(temp, verbs)) result += temp + " ";
    else throw runtime_error("No\n");
    return result;
}
string offer()
{
    string offer_s = collocation();
    string temp;
        temp = get();
        if(temp == "."){
            offer_s += temp;
            return offer_s;
        }
        if(check(temp, unions)) offer_s += temp + " ";
        else throw runtime_error("No\n");
        offer_s = collocation();
        temp = get();
        if(temp == "."){
            offer_s += temp;
            return offer_s;
        }
        throw runtime_error("No\n");
}

int main()
{
    while(true){
    try
    {
        string offer_m = offer();
        cout << "Yes\n";
    }
    catch(exception &e)
    {
        cout << e.what();
    }
    }
    return 0;
}

