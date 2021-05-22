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

using namespace std;

int input(double &first_number,double &second_number, char &op);

double summ (const double &x, const double &y);
double diff (const double &x, const double &y);
double multiply (const double &x, const double &y);
double divide (const double &x, const double &y);
double ost (const double &x, const double &y);

int main()
{
        double x, y, result;
        char op;

        while(true){
            if(input(x,y,op) == -1){
                cerr << "Error: Input error. Restart program and enter values same as example(: x + y)";
                return -1;
            }
            switch(op)
            {
            case '+':
                result = summ(x,y);
                break;
            case '-':
                result = diff(x,y);
                break;
            case '*':
                result = multiply(x,y);
                break;
            case '/':
                result = divide(x,y);
                break;
            case '%':
                result = ost(x,y);
                break;
            default:
                cout << "Undefined operator. Enter data again\n";
                continue;
            }
            cout << "Result of expression = " << result << '\n'
                 << "Want continue?(\"y\" for yes and someone else for no)\n" << ':';
            while(iscntrl(cin.peek()))getchar();
            if(getchar() == 'y');
            else {
                cout << "End program." << endl;
                break;
            }
        }
        return 0;
}


int input(double &first_number, double &second_number, char &op)
{
    cout << "Enter expression (x operator y)\n";
    cin >> first_number >> op >> second_number ;
    if(!cin.good()) return -1;
    return 0;
    }

double summ (const double &x, const double &y)
{
    return x + y;
}

double diff (const double &x, const double &y)
{
    return x - y;
}

double multiply (const double &x, const double &y)
{
    return x * y;
}

double divide (const double &x, const double &y)
{
    return x / y;
}

double ost (const double &x, const double &y)
{
    return x -  ((int)(x / y)) * y;
}
