#ifndef STORAGE_H
#define STORAGE_H

class Storage
{
private:
    int *pobj;
    unsigned counter = 0;
public:
    Storage() :pobj(nullptr){}
    Storage(unsigned);
    Storage(int*);
    Storage(Storage &Storage_cpy)
            : pobj(Storage_cpy.pobj), counter(Storage_cpy.counter){}
    ~Storage();
};

#endif // STORAGE_H
