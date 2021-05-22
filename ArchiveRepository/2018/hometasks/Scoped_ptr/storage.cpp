#include "storage.h"

Storage::~Storage()
{
    --counter;
    if(counter != 0){
        pobj = nullptr;
    }
    else delete pobj;
}
Storage::Storage(unsigned num = 1)
{
    pobj = new int(num);
    ++counter;
}
Storage::Storage(int *pobj_v)
{
    pobj = pobj_v;
    ++counter;
}
