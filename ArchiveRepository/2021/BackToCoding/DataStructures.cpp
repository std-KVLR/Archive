#include "DataStructures.h"

/*
            DS CONTROLLER
*/


typedef myDataStructures::DataStructuresController DSC;

DSC::DataStructures DSC::ds = DSC::DataStructures::Array;
std::string DSC::currentdsName;
size_t DSC::memoryConsInfo = 0;
size_t DSC::amountElem = 0;
size_t DSC::oneElemSize = 0;

void DSC::printInfo(std::ostream &stream)
{
    stream << "Current data structure is "
              << currentdsName << ".\nAmount of elements "
              << amountElem << ".\n"
              << "Size of one element " << oneElemSize
              << " bytes.\nMemory consumption was " << memoryConsInfo
              << " bytes." << std::endl;
}


/*
            DS CONTROLLER
*/









