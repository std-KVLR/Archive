#include "Scoped_ptr.h"


Scoped_ptr& Scoped_ptr::operator=(const Scoped_ptr& rvalue)
{
    data = rvalue.data;
}



