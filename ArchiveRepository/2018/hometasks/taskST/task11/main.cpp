#include <iostream>
#include <fstream>
#include <clocale>
#include <windows.h>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int symb_define(int ch);
void filename(const char* inputMsg, const size_t buffsize,
              istream& ist, string& nameStore);
void readingChar(istream& ist, string& buffer);
vector<int> symbClass(const string& line);


struct DupNum
{
    double num = 0;
    size_t dup = 1;

    DupNum() = default;
    DupNum(double numV, size_t dupV) :num(numV), dup(dupV) {}
};

int findFirstCopy(const vector<DupNum>& workW, double num)
{
    for(size_t i = 0; i < workW.size(); ++i){
        if(workW[i].num == num) return i;
    }
    return -1;
}
int main()
{
    ifstream ifs("digits.txt");
    if(!ifs) throw -1;
    vector<DupNum>buffer;
    int pos;
    for(double temp; ifs >> temp; ){
        if((pos = findFirstCopy(buffer, temp)) != -1){
            ++buffer[pos].dup;
        }
        else buffer.push_back(DupNum(temp,1));
    }

    for(auto &el : buffer)
    {
        cout << el.num << ' ' << el.dup << '\n';
    }
    return 0;
}












void task11_14()
{
    ifstream ifs("digits.txt");
    if(!ifs) throw -1;
    vector<double>buffer;

    for(double temp; ifs >> temp; ){
        buffer.push_back(temp);
    }
    ifs.close();

    fstream ofs("digitsout.txt", ios_base::in | ios_base::out);
    if(!ofs) throw -1;

    ofs << setprecision(8) << scientific;
    for(size_t i = 1; i - 1 < buffer.size(); ++i){
            double test = buffer[i-1];
            ofs << '|' << setw(20) << buffer[i - 1];
            if(!(i % 4)) ofs << "|\n";
    }
    ofs.seekg(ofs.tellg());
    char ch;
    ofs.get(ch);
    if( ch != '|'){
        ofs << "|";
    }
    ofs.close();

}

int task11_13()
{
    string flname;
    filename("Enter input file name: ", 100, cin, flname);
    ifstream ifs(flname);
    if(!ifs) return -1;
    string buffer;

    readingChar(ifs, buffer);
    ifs.close();

    vector<int> symbCount = symbClass(buffer);
    const vector<string> symbLabels = {"Control", "Separate&Control", "Punctuation",
                                "Uppercase letter", "Lowercase letter", "Digit"};
    filename("Enter output file name: ", 100, cin, flname);
    ofstream ofs(flname);
    if(!ofs) return -1;

    for(size_t i = 0; i < symbCount.size(); ++i){
            ofs << '|' << symbLabels[i]
                << ": " << symbCount[i];
    }
    ofs << '|';
    ofs.close();
    return 0;
}
vector<int> symbClass(const string& line)
{
    vector<int> result(6,0);

    for(char c : line)
    {
        ++result[symb_define(c) - 1];
    }
    return result;
}


void readingChar(istream& ist, string& buffer)
{
    char ch;
    if(!ist) throw -1;

    while(ist.get(ch))
    {
        buffer.push_back(ch);
    }
    if(ist.eof()) ist.clear();
    else throw -1;
}

int symb_define(int ch)
{
    const int cntrlSymbTerm = 1;
    const int cntrlseparSymbTerm = 2;
    const int punctSymbTerm = 3;
    const int upperSymbTerm = 4;
    const int lowerSymbTerm = 5;
    const int digitSymbTerm = 6;

    int result = 0;

    if(!isprint(ch) || ch == ' '){
        result = cntrlSymbTerm;
        if(isspace(ch)){
            result = cntrlseparSymbTerm;
        }
    }
    else{
        if(ispunct(ch)){
            result = punctSymbTerm;
        }
        else{
            if(isalpha(ch)){
                if(isupper(ch)) result = upperSymbTerm;
                else result = lowerSymbTerm;
            }
            else result = digitSymbTerm;
        }
    }
    return result;
}




void task11_12()
{
    fstream fs("reverse.txt", ios_base::in | ios_base::out);
    if(!fs) throw -1;
    string tempBuf;
    vector<string> buffer;

    while(fs >> tempBuf)
    {
        buffer.push_back(tempBuf);

    }
    if(fs.eof()) fs.clear();
    else throw -1;

    fs.seekg(0);
    for(auto it = buffer.end() -1; it >= buffer.begin(); --it)
    {
        fs << *it << ' ';
    }
}
void task11_11()
{
    fstream fs("reverse.txt", ios_base::in | ios_base::out);
    if(!fs) throw -1;
    string buffer;

    char ch;
    while(fs.get(ch))
    {
        buffer.push_back(ch);
    }
    if(fs.eof()) fs.clear();
    else throw -1;

    fs.seekg(0);
    for(auto it = buffer.end() -1; it >= buffer.begin(); --it)
    {
        fs << *it;
    }
    fs.close();
}



















void filename(const char* inputMsg, const size_t buffsize,
              istream& ist, string& nameStore)
{
    if(!nameStore.empty()) nameStore.clear();

    cout << inputMsg;
    char name[buffsize];
    ist.getline(name,buffsize);

    OemToCharA(name,name);
    nameStore = name;
}
unsigned char my_tolower(unsigned char ch)
{
    if(ch >= 65 && ch <= 90) return tolower(ch);
    else if( ch >= 192 && ch <= 223) return ch + 32;
    else return ch;
}

int task11_1()
{
    setlocale(LC_ALL, "Russian");
    string name;
    filename("Введите имя файла для ввода: ", 100, cin, name);
    fstream fs(name, ios_base::in);
    try
    {
        if(!fs) throw runtime_error("ошибка: файл для ввода отсутствует");
        char ch;
        string buffer;
        while(fs.get(ch)){
               if(isalpha(ch))ch = my_tolower(ch);
               buffer.push_back(ch);
        }
        fs.close();
        filename("Введите имя файла для вывода: ", 100, cin, name);
        fstream fs(name, ios_base::out);
        fs << buffer;
        fs.close();
    }
    catch(const runtime_error &e)
    {
        cerr << e.what() << ends;
        fs.close();
    }
    return 0;
}

bool isvowel(unsigned char ch)
{
    const int vowel_arr[32] = {65, 69, 73, 79, 81, 85, 89,
                             97, 101, 105, 111, 113, 117, 121,
                             192, 197, 200, 206, 211, 219, 221, 222, 223,
                             224, 229, 232, 238, 243, 251, 253, 254, 255};
    for(size_t i = 0; i < 32; ++i)
    {
        if(ch == vowel_arr[i])return true;
    }
    return false;
}

void task11_2()
{
    setlocale(LC_ALL, "Russian");
    string name;
    filename("Введите имя файла для ввода: ", 100, cin, name);
    fstream fs(name, ios_base::in);
    try
    {
        if(!fs) throw runtime_error("ошибка: файл для ввода отсутствует");
        char ch;
        string buffer;
        while(fs.get(ch)){
                if(!isvowel(ch))buffer.push_back(ch);
        }
        fs.close();
        ofstream ofs(name);
        ofs << buffer;
        ofs.close();
    }
    catch(const runtime_error &e)
    {
        cerr << e.what() << ends;
        fs.close();
    }
}

template <class T>

char* as_bytes(T& i)
{
    void* addr = &i;
    return static_cast<char*>(addr);
}
void task11_8()
{
    ifstream ifs("testfile.txt");
    if(!ifs) throw -1;
    vector<char> char_v;
    char c;
    while(ifs.get(c))
    {
        char_v.push_back(c);
    }
    ofstream ofs("output", ios_base::binary);
    for(size_t i = 0; i < char_v.size(); ++i){
        ofs.write(as_bytes(char_v[i]), sizeof(char));
    }

    ifs.close();
    ofs.close();
    ifs.open("output", ios_base::binary);
    char_v.clear();
    while(ifs.read(as_bytes(c), sizeof(char))) char_v.push_back(c);
    ofs.open("outt.txt");

    for(size_t i = 0; i < char_v.size(); ++i){
        ofs << char_v[i];
    }
}

void convDetToSpace(char &ch, const string& det)
{
    for(size_t i = 0; i < det.size(); ++i)
    {
        if(ch == det[i]) ch = ' ';
    }
}
void convDetToSpace_string(string &s, const string& det)
{
    for(char &c : s) convDetToSpace(c,det);
}
vector<string> split(const string& s, const string& det)
{
    vector<string> result;
    string form_string(s);
    convDetToSpace_string(form_string, det);
    istringstream ss(form_string);
    string temp;
    while(ss >> temp)
    {
        result.push_back(temp);
    }
    return result;
}
