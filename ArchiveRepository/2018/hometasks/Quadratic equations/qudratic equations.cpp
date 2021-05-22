#include "qudratic_equations.h"


int qe_find_root(double &x1, double &x2, const double &a, const double &b, const double &c)
{
    double D = b*b - 4*a*c;
    if(D > 0){
        x1 = ((-b) + sqrt(D)) / (2 * a);
        x2 = ((-b) - sqrt(D)) / (2 * a);
        return 2;
    }
    else if(D < 0){
        x1 = NAN;
        x2 = NAN;
        return 0;
    }
    else{
        x1 = (-b) / 2 * a;
        x2 = NAN;
        return 1;
    }
}
