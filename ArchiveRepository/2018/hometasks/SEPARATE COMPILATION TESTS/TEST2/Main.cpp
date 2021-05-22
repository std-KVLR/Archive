#include "exsisise1.h"
#include <iostream>

int main()
{

       int my_number;

       if(inputNumber(my_number)){
		std::cerr << "InputError. Reload program and try again.";
		return 1;
       }
       outputNumber(my_number);      
     
       return 0;
}