#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>
struct Point
{
    double x;
    double y;
    Point() : x(0), y(0) {}
    Point(double valX, double valY) : x(valX), y(valY) {}
};

Point inputPoint(std::istream& is);
void printPoint(std::ostream& os, const Point& p);
std::vector<Point> fill_vector(size_t elemNum, std::istream& ist);
void vec_to_data(const std::vector<Point>& pVec, std::ostream& ofs);
std::vector<Point> data_to_vec(std::istream& ist);
bool operator==(const Point& p1, const Point& p2);
#endif // POINT_H
