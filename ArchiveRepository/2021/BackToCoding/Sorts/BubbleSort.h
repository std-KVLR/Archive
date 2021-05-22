#ifndef BUBBLESORT_H
#define BUBBLESORT_H


#include <algorithm>
namespace kvlrAlgo
{

namespace Sorts
{


template <typename Iterator> void bubbleSort(Iterator begin, Iterator end, size_t* permutations, size_t* comparisons)
{
    for(auto i = begin, tail = end - 1; tail != begin; --tail){
        while(i != tail){
            if(*i > *(i + 1)) {
                std::swap(*i, *(i + 1));
                ++(*permutations);
            }
            ++i, ++(*comparisons);
        }
        i = begin;
    }
}


}

}

#endif // BUBBLESORT_H
