#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H

#include <string>
#include <iostream>

#include <Sorts/BubbleSort.h>



namespace kvlrAlgo
{

class AlgorithmController
{

private:

    //Singleton implementation

    AlgorithmController() = delete;
   ~AlgorithmController() = delete;
    AlgorithmController(const AlgorithmController&) = delete;
    AlgorithmController& operator=(const AlgorithmController&) = delete;
    //

    //fields
    static size_t permutations;
    static size_t comparisons;
    static size_t counter;
    static size_t lastContainerElemSize;
    static std::string algName;
    static std::string memoryConsInfo;

    //boilerplate fix
    static void logging(const size_t elemNum, const char* algName_, const char* memInfo);

public:

    //Sorts
    template<typename T> static void bubbleSort(const T& container, const size_t num);
    template<typename T> static void quickSort(const T& container, const size_t num);
    template<typename T> static void mergeSort(const T& container, const size_t num);
    template<typename T> static void insertionSort(const T& container, const size_t num);
    template<typename T> static void selectionSort(const T& container, const size_t num);
    template<typename T> static void shellSort(const T& container, const size_t num);
    template<typename T> static void radixSort(const T& container, const size_t num);

    //print info
    static void printInfo(std::ostream &stream = std::cout);

};

template<typename T>void AlgorithmController::bubbleSort(const T& container, const size_t num)
{
    Sorts::bubbleSort(container.begin(), container.end(), &permutations, &comparisons);
    logging(num, "Bubble Sort", "O(1)");
}

}







#endif // MYALGORITHMS_H
