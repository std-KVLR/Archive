#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>
using namespace std;



class Iterator {
public:
    virtual double* next() = 0;
};

class VectorIterator: public Iterator {
public:
    VectorIterator(vector<double>& dVec)
    {
        if(dVec.empty()) throw runtime_error("error: vector is empty");
        start = &dVec[0];
    }

    double* next() {return start + it++;}

private:
    double* start;
    size_t it = 0;

};


int main()
{

    return 0;
}
