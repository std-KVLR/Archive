#include "Point.h"




Point inputPoint(std::istream& is)
{
    const int bad_input = -1;

    double valX, valY;
    char ch1, ch2, ch3;

    is >> ch1 >> valX
       >> ch2 >> valY >> ch3;
    if(!is || ch1 != '(' ||
        ch2 != ',' || ch3 != ')')throw bad_input;
    return Point(valX,valY);
}

void printPoint(std::ostream& os, const Point& p)
{
    os << '(' << p.x << ','
       << p.y << ')';
}

std::vector<Point> fill_vector(size_t elemNum, std::istream& ist)
{
    std::vector<Point> work_v(elemNum);

    for(size_t i = 0; i < elemNum;++i){
            std::cout << i + 1 << ": ";
            work_v[i] = inputPoint(ist);
    }
    return work_v;
}


void vec_to_data(const std::vector<Point>& pVec, std::ostream& ofs)
{
      const int empty_vector = -1;

      if(pVec.empty())throw(empty_vector);

      for(auto &p : pVec){
            printPoint(ofs,p);
            ofs << '\n';
      }
}


std::vector<Point> data_to_vec(std::istream& ist)
{
    const int input_error = -1;
    ist.exceptions(ist.exceptions()|std::ios_base::badbit);
    std::vector<Point> pVec;
    double valX, valY;
    char ch1,ch2,ch3;

    while(ist >> ch1 >> valX >> ch2 >> valY >> ch3){
        if(ch1 != '(' || ch2 != ',' || ch3 != ')'){
                std::cerr << "Error: input format error\n";
                throw input_error;
        }
        pVec.push_back(Point(valX, valY));
    }
    if(ist.fail() && !ist.eof()){
        std::cerr << "Error: input data error\n";
        throw input_error;
    }
    return pVec;
}

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}
/*
Point::Point()
{
    //ctor
}

Point::~Point()
{
    //dtor
}

*/
