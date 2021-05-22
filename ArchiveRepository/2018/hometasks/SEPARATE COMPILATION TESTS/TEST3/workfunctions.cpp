#include "workfunctions.h"



void inputDigits(double &x, char name)
{
 while(1){
	 std::cout << "Enter " << name <<": ";
	 if(std::cin >> x) break;
	 std::cin.clear();
	 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	 std::cerr << "Input incorrect, please try again.\n";
 }
 return;
}

double exsCalc(double a, double b, double f)
{
 double result;

 if(a != 0) result = a + b - f/a;
 else{
	std::cerr << "Error. Zero division attempt";
	return nan(NULL);
 }
 result += f * a * a - (a + b);
 return result;
}	



