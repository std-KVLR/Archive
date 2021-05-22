#include "workfunctions.h"
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
  double a,b,f;
  
  cout << "Enter arguments:\n";
  inputDigits(a, 'a'), inputDigits(b, 'b'),  inputDigits(f, 'f');
  cout << "Calculate expression: x = (a + b - f / a) + f * a * a - (a + b)\n";
  double result = exsCalc(a,b,f);
  if(isnan(result)) return -1;
  cout << "Result is: " << result;
  return 0;

}