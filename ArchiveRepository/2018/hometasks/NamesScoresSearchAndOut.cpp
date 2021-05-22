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

void input_f(vector <string> &name_sq, vector <int> &points_sq);
int test_f_uniq_name(vector <string> work_v);
int print_f(const vector <string> &name_sq, const vector <int> &points_sq);
int console_f(const vector <string> &name_sq, const vector <int> &scores_sq );
void console_f_command_l_f_scor(const int &a, const vector <string> &name_sq, const vector <int> &scores_sq);
void console_f_command_l_f_name(const string &search_name, const vector <string> &name_sq, const vector <int> &scores_sq);




int main()
{
    vector <string> names;
    vector <int> scores;
    input_f(names, scores);

    if((test_f_uniq_name(names)) == -1){ cerr << "Error: names must not be repeated.\n"; return -1;}
    //if((print_f(names, scores)) == -1) { cerr << "Error: one of the buffer is empty.\n"; return -1;}
    console_f(names, scores);
    return 0;


}
int console_f(const vector <string> &name_sq, const vector <int> &scores_sq )
{
    string work_s, temp_buff;
    cout << "Input:\n";
    while(cin >> work_s){
        if(isdigit(work_s[0])){
                console_f_command_l_f_scor(atoi(&work_s[0]), name_sq, scores_sq);
        }
        else console_f_command_l_f_name(work_s, name_sq, scores_sq);
        fflush(stdin);
    }
    return 0;

}
void console_f_command_l_f_name(const string &search_name, const vector <string> &name_sq, const vector <int> &scores_sq)
{
    bool flag = false;
    for(size_t i = 0, endv = name_sq.size(); i < endv; ++i){
        if(search_name == name_sq[i]){
            cout << name_sq[i] << ": " << scores_sq[i] << '\n';
            flag = true;
            break;
        }
    }
    if(!flag) cout << "Score not found.\n";
}
void console_f_command_l_f_scor(const int &a, const vector <string> &name_sq, const vector <int> &scores_sq)
{
    bool flag = false;
    for(size_t i = 0, endv = scores_sq.size(); i < endv; ++i){
        if(a == scores_sq[i]){
            cout << name_sq[i] << ' ';
            flag = true;
        }
    }
    cout << '\n';
    if(!flag) cout << "Score not found.\n";
}

int test_f_uniq_name(vector <string> work_v)
{
    auto it_b = work_v.begin(), it_end = work_v.end();
    sort(it_b, it_end);
    string temp;
    while(true){
        temp = *it_b;
        ++it_b;
        if(it_b == it_end) return 0;
        if(*it_b == temp) return -1;
    }
}

int print_f(const vector <string> &name_sq, const vector <int> &points_sq)
{
   if(name_sq.empty() || points_sq.empty()) return -1;
   cout << "Output:\n";
   for(size_t i = 0, endv = name_sq.size(); i < endv; ++i){
        cout << name_sq[i] << ' ' << points_sq[i] << '\n';
   }
   return 0;
}

void input_f(vector <string> &name_sq, vector <int> &points_sq)
{
    cout << "Start input enter strings like a example: (Joe 17)\n";
    string work_str, word_str, digit_str;
    while(getline(cin, work_str)){

        if(work_str == "No more") {cout << "Input exit.\n"; break;}

        for(auto i_b = work_str.begin(), i_e = work_str.end();
            i_b < i_e; ++i_b){
                while(*i_b == ' ' || *i_b == '\t') ++i_b;
                if(isdigit(*i_b)) digit_str += *i_b;
                else word_str += *i_b;
        }

        points_sq.push_back(atoi(&digit_str[0]));
        name_sq.push_back(word_str);
        word_str.clear();
        digit_str.clear();
        work_str.clear();
    }
}
