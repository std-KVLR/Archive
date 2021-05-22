#include "Money.h"


Money::Money(std::istream &is)
{
    int banknotes, coins;
    char p;
    std::string curren_v;
    is >> banknotes >> p
       >> coins >> curren_v;
    conv_unit = (is_Currency(curren_v)) ? banknotes * 100 + coins : throw(input_error);
}

void Money::conv_to(currency cur)
{
    const float USD_to_EUR = 0.8651;
    const float EUR_to_USD = 1.1559;
    const float RUB_to_EUR = 0.01308;
    const float EUR_to_RUB = 76.4260;
    const float USD_to_RUB = 66.1173;
    const float RUB_to_USD = 0.01512;


    if(mon_c == cur) return;
    double conv_mon = conv_unit;

    if(mon_c == USD)
    {
        switch(static_cast<size_t>(cur))
        {
            case 1:
                conv_mon *= USD_to_EUR;
                mon_c = EUR;
                break;
            case 2:
                conv_mon *= USD_to_RUB;
                mon_c = RUB;
                break;
        }
    }
    else if(mon_c == EUR)
    {
        switch(static_cast<size_t>(cur))
        {
            case 0:
                conv_mon *= EUR_to_USD;
                mon_c = USD;
                break;
            case 2:
                conv_mon *= EUR_to_RUB;
                mon_c = RUB;
                break;
        }
    }
    else if(mon_c == RUB)
    {
        switch(static_cast<size_t>(cur))
        {
            case 0:
                conv_mon *= RUB_to_USD;
                mon_c = USD;
                break;
            case 1:
                conv_mon *= RUB_to_EUR;
                mon_c = EUR;
                break;
        }
    }
    double temp_rem = conv_mon - static_cast<int>(conv_mon);
    conv_mon += (temp_rem > 0.5) ? (1 - temp_rem) : -(1 - temp_rem);
    conv_unit = conv_mon;
}

std::ostream& operator<<(std::ostream &os, const Money &obj)
{
    std::string cur_c;

    switch(static_cast<size_t>(obj.get_curr()))
    {
        case 0: cur_c = " USD"; break;
        case 1: cur_c = " EUR"; break;
        case 2: cur_c = " RUB"; break;
    }
    return os << obj.get_mon()/100.0 << cur_c;
}

Money operator+(const Money &op1, const Money &op2)
{
    Money temp = op2;
    Money::currency need = op1.get_curr();
    if(need != op2.get_curr()){
            temp.conv_to(need);
    }
    return Money(op1.get_mon() + temp.get_mon(), need);
}
Money operator-(const Money &op1, const Money &op2)
{
    Money temp = op2;
    Money::currency need = op1.get_curr();
    if(need != op2.get_curr()){
            temp.conv_to(need);
    }
    return Money(op1.get_mon() - temp.get_mon(), need);
}
