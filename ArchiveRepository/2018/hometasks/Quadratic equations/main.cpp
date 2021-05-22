#include <iostream>
#include "input.h"
#include "qudratic_equations.h"

using namespace std;

int main()
{
    double a, b, c, x1, x2;

    if(input_equations(a, b, c)) return 1;
    switch(qe_find_root(x1, x2, a, b, c))
    {
    case 0:
        cout << "Equation has no roots.";
        break;
    case 1:
        cout << "Equation has one root." << x1;
        break;
    case 2:
        cout << "Roots of equation x1 = " << x1 << " x2 = " << x2;
        break;
    }
    return 0;
}
