#include "Sales_data.h"

Sales_data::Sales_data(const Sales_data &Sales_data_copy)
{
    bookNo = Sales_data_copy.bookNo;
    units_sold = Sales_data_copy.units_sold;
    revenue = Sales_data_copy.revenue;
}

inline double Sales_data::avg_price()const
{
     return units_sold ? revenue/units_sold : throw std::runtime_error("error: divide by zero.\n");

}
std::istream& operator>>(std::istream &is, Sales_data &input_data)
{
        const int throw_eof = -1;

        std::cout << "Enter ISBN: ";
        std::cin >> input_data.bookNo;
        if(!std::cin.fail())std::cout << "Enter number of sales: ";
        std::cin >> input_data.units_sold;
        if(!std::cin.fail())std::cout << "Enter the price for one book: ";
        double price = 0;
        std::cin >> price;
        input_data.revenue = price * input_data.units_sold;
        if(std::cin.good());
        else if(std::cin.eof()) throw (throw_eof);
        else throw std::runtime_error("Input error.\n");

    return is;
}
std::ostream& operator<<(std::ostream &os,const Sales_data &output_data)
{
    os << '\n' << "ISBN: " << output_data.bookNo;
    os << '\n' << "Units_sold: " << output_data.units_sold;
    os << '\n' << "Revenue: " << output_data.revenue;

    return os;
}
Sales_data& Sales_data::operator=(const Sales_data &rvalue)
{
    bookNo = rvalue.bookNo;
    units_sold = rvalue.units_sold;
    revenue = rvalue.revenue;
    return *this;
}
Sales_data operator+(const Sales_data &op1, const Sales_data &op2)
{
    if(op1.bookNo != op2.bookNo) throw std::runtime_error("ISBN's not match.\n");
    return Sales_data(op1.bookNo, op1.units_sold + op2.units_sold, op1.revenue + op2.revenue);
}
Sales_data& Sales_data::operator+=(const Sales_data &rvalue)
{
    if(bookNo != rvalue.bookNo) throw std::runtime_error("ISBN's not match.\n");
    units_sold += rvalue.units_sold;
    revenue += rvalue.revenue;
    return *this;
}
