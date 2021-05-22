#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include "MyDataStructuresArray.h"

namespace myDataStructures
{

class DataStructuresController
{
public:
    enum DataStructures{Array, Stack, List, Queue, Graph, Three, BinaryThree, None};

private:

    //Singleton implementation

    DataStructuresController() = delete;
   ~DataStructuresController() = delete;
    DataStructuresController(const DataStructuresController&) = delete;
    DataStructuresController& operator=(const DataStructuresController&) = delete;
    //

    //fields

    static DataStructures ds;
    static std::string currentdsName;
    static size_t memoryConsInfo;
    static size_t amountElem;
    static size_t oneElemSize;

    static void logging(DataStructures ds_, const  char* name, size_t memInfo,
                                              size_t elemNum, size_t elemSize)
    {
        ds = ds_;
        currentdsName = name;
        memoryConsInfo = memInfo;
        amountElem = elemNum;
        oneElemSize = elemSize;
    }

public:

    template<typename T> static void dsInit(myDataStructures::Array<T>& container)
    {
       logging(DataStructures::Array, "Array", (sizeof(T) * container.size())+ sizeof(T*) * 2, container.size(), sizeof(T));
    }

    //
    static void printInfo(std::ostream &stream = std::cout);

};

template<typename T> class Stack {};
template<typename T> class List {};
template<typename T> class Queue {};
template<typename T> class Graph {};
template<typename T> class Three : public Graph<T> {};
template<typename T> class BinaryThree : public Three<T> {};

}




#endif // DATASTRUCTURES_H
