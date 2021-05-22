#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:

    Rational() = default;
    Rational(double num, double denum)
            : numenator(num), denumenator(denum){}
    Rational(double num) : numenator(num), denumenator(){}

    double get_num() const { return numenator; }
    double get_denum() const { return denumenator; }

    double conv_to_doub() const { return numenator/denumenator; }
    void operator=(const Rational &rvalue)
    {
        if(&rvalue != this){
          this->numenator = rvalue.numenator, this->denumenator = rvalue.denumenator;
        }
    }

private:
    double numenator = 1.0;
    double denumenator = 1.0;
};

std::ostream& operator<<(std::ostream&, const Rational&);
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);
bool operator==(const Rational&, const Rational&);
bool operator!=(const Rational&, const Rational&);


inline int calc_GCD(int a, int b)
{
	return b ? calc_GCD (b, a % b) : a;
}




#endif // RATIONAL_H_INCLUDED
