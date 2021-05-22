#include <iostream>
#include <string>
#include <vector>
#include "ProgramBlocks.h"
#include "DataStructures.h"
#include "MyAlgorithms.h"
int main(int argc, char **argv)
{

  try
    {
        prblocks::DataInputController c1((size_t)argc, (const char**)(argv));
        c1.debug();
        std::string args = c1.get_args_str();
        myDataStructures::Array<int,0> a1;
        std::string tmp;
        size_t i = 0;
        while(i < args.size())
        {
            for(; args[i] != ' ' && i < args.size();++i) tmp += args[i];
            a1.push(std::stoi(tmp));
            tmp.clear();
            ++i;
        }
        kvlrAlgo::AlgorithmController::bubbleSort(a1,a1.size());
        kvlrAlgo::AlgorithmController::printInfo();
        myDataStructures::DataStructuresController::dsInit(a1);
        myDataStructures::DataStructuresController::printInfo();
    }
    catch(...)
    {
        std::cerr << "Somes happend wrong! Restart the programm and try again." << std::endl;
        return -1;
    }

    return 0;
}
