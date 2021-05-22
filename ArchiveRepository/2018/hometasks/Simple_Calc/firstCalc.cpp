#include "firstCalc.h"




int input(double &first_number, double &second_number, char &op)
{

    cout << "Enter expression (x operator y)\n";
    cin >> first_number >> op >> second_number ;
    if(!cin.good()) return -1;
    return 0;
}

int inputv2(double &first_number, double &second_number, char &op)
{

    string number1, number2;

    cout << "Enter expression (x operator y)\n";

    cin >> number1 >> op >> number2;

    first_number = test_Num(number1);
    second_number = test_Num(number2);

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
