#ifndef SATTERHELPERS_H
#define SATTERHELPERS_H


namespace SatterHelpers
{

template <typename T> void copy_construct(T *p, const T& val)
{
    new (p) T (val);
}

template <typename T> void destroy (T* p)
{
    p->~T();
}

template <typename FwdIter> void destroy(FwdIter first, FwdIter last)
{
    while(first != last) destroy(&*first++);
}

}


#endif // SATTERHELPERS_H
