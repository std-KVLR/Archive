#ifndef SCOPED_PTR_H
#define SCOPED_PTR_H

#include "storage.h"
class Scoped_ptr
{
private:
    Storage data;
public:
    Scoped_ptr() = default;
    Scoped_ptr(unsigned num) :data(num){}
    Scoped_ptr(int *pobject_v) :data(pobject_v){}
    Scoped_ptr(Scoped_ptr&);
    Scoped_ptr& operator=(const Scoped_ptr&);
    Scoped_ptr operator=(const int*);
};
#endif // SCOPED_PTR_H
