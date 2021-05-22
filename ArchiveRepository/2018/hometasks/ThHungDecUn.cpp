#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;

int input_ch(short &counter);
void my_out(int digit, short counter);


int main()
{
    short counter;
    int number = input_ch(counter);
    my_out(number, counter);
    cout << number % 1000;
}

void my_out(int digit, short counter)
{
    if(counter <= 0 && counter > 4){
        throw runtime_error("error: the number is zero, or goes beyond the four-digit");
    }
    string out_a[4] = {"unit", "decade", "thousand", "hundred"};
    int div_a[4] = {1,10,100,1000};
    while(counter > 0){
        cout << digit / div_a[counter - 1]
             << " is " << out_a[counter - 1] << '\n';
        digit %= div_a[counter - 1];
        --counter;
    }
}



int input_ch(short &counter)
{
    char c;
    counter = 0;
    string result;
    while(cin >> c){
        if(isdigit(c)){result += c; ++counter;}
        else if(c == '|'){cout << "Input complete\n"; break;}
        else throw runtime_error("error: value is not a number");
    }
    return atoi(&result[0]);
}
