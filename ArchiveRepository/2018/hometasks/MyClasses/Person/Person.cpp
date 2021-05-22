#include "Person.h"


std::istream& operator>>(std::istream& is, Person &input_data)
{
    std::cout << "Enter name: ";
    is >> input_data.name;
    is.get();
    std::cout << "Enter address: ";
    getline(is, input_data.address);
    return is;
}
std::ostream& operator<<(std::ostream& os, Person &output_data)
{
    os << "Name: " << output_data.name << " | "
       << "Address: " << output_data.address;
    return os;
}
