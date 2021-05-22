#ifndef FIRST_CALC_H
#define FIRST_CALC_H

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
#include "strTointAndInv.h"

using namespace std;

int input(double &first_number,double &second_number, char &op);
int inputv2(double &first_number, double &second_number, char &op);

double summ (const double &x, const double &y);
double diff (const double &x, const double &y);
double multiply (const double &x, const double &y);
double divide (const double &x, const double &y);
double ost (const double &x, const double &y);
#endif
