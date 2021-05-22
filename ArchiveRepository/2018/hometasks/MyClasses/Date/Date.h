#ifndef MY_H
#define MY_H

#include <iostream>
#include <ctime>
namespace Chrono
{
    class Date
    {
    public:
        enum Month{jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
        class Invalid{};

        Date();
        Date(int year, Month month_v, int day);

        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }

        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        int y;
        Month m;
        int d;

        unsigned long day_seq;
        unsigned long day_seq_calc(const Date&);
    };
    bool is_date(int y, Date::Month m, int d);
    inline bool leapyear(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }
    Date next_workday();
    size_t week_of_the_year();
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);
    std::ostream& operator<<(std::ostream &os, const Date& d);
    std::istream& operator>>(std::istream &is, const Date& dd);
} // Chrono
#endif // MY
