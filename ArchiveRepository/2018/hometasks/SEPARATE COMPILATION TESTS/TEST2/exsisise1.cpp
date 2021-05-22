#include "exsisise1.h"

int inputNumber(int &number)
{
	number = 0;
	std::cout << "Enter integer number: ", std::cin >> number;
	if(number == 0){
		std::cerr << " Number is 0. Restart program and try again.\n";
		return 1;
	}
	else if(number >= 100000){
		 std::cerr << "Number overflow (more than 100000)."
			   <<  "Restart program and try again.\n";
		 return 1;
	}
	return 0;
}
int outputNumber(int number)
{
	char buff[6];

	for(short i = 4; number > 0; number /= 10, --i){
		buff[i] = (number % 10) + '0';
	}
	buff[5] = '\0';
	std::cout << "List of digits:\n";
	for(short i = 0; buff[i] != '\0'; ++i){
		std::cout << i + 1 << ": " << buff[i] << '\n';
	}
	return 0;
}
		

