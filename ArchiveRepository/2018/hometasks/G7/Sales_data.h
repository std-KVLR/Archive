#ifndef SALES_D_H
#define SALES_D_H

#include <string>
#include <iostream>
#include <stdexcept>
class Sales_data
{
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;

public:
//  *******************_Constructors_******************************
    Sales_data() = default;
    Sales_data(const std::string &ISBN, const unsigned &units_s, const double &revenue_s)
                :bookNo(ISBN), units_sold(units_s), revenue(revenue_s)
                {std::cout << "Main constuctor" << '\n';}
    Sales_data(const std::string &ISBN) : Sales_data(ISBN, 0, 0)
                                        {std::cout << "ISBN constructor" << '\n';}
    Sales_data(std::istream &is):Sales_data()
    {
        is >> *this;
        std::cout << "Istream constuctor" << '\n';
    }

    Sales_data(const Sales_data &Sales_data_copy);

//  ***************************************************************
    std::string get_ISBN() const {return bookNo;}
//  ***************************************************************
    Sales_data& operator=(const Sales_data &rvalue);
    Sales_data& operator+=(const Sales_data &rvalue);

    friend Sales_data operator+(const Sales_data &op1, const Sales_data &op2);
    friend std::istream& operator>>(std::istream &is, Sales_data &input_data);
    friend std::ostream& operator<<(std::ostream &os, const Sales_data &output_data);
};

Sales_data operator+(const Sales_data &op1, const Sales_data &op2);
std::istream& operator>>(std::istream &is, Sales_data &input_data);
std::ostream& operator<<(std::ostream &os, const Sales_data &output_data);

#endif // SALES_D_H
