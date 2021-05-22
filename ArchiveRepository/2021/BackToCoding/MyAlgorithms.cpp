#include "MyAlgorithms.h"

// static fields initializing

size_t kvlrAlgo::AlgorithmController::permutations = 0;
size_t kvlrAlgo::AlgorithmController::comparisons = 0;
size_t kvlrAlgo::AlgorithmController::counter = 0;
size_t kvlrAlgo::AlgorithmController::lastContainerElemSize = 0;
std::string kvlrAlgo::AlgorithmController::algName;
std::string kvlrAlgo::AlgorithmController::memoryConsInfo;





//methods

void  kvlrAlgo::AlgorithmController::printInfo(std::ostream &stream)
{
    stream << "Last executed algorithm is "
              << algName << ".\nSorted sequence of "
              << lastContainerElemSize << " elements.\n"
              << "Permutations = " << permutations
              << ".\nComparisons = " << comparisons
              << ".\nTotal operations number is " << counter
              << ".\nMemory consumption was " << memoryConsInfo << '.'
              << std::endl;
}


//private section


void kvlrAlgo::AlgorithmController::logging(const size_t elemNum, const char* algName_, const char* memInfo)
{
    lastContainerElemSize = elemNum;
    algName = algName_;
    counter = permutations + comparisons;
    memoryConsInfo = memInfo;
}


