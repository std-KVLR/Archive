#ifndef PROGRAMBLOCKS_H_INCLUDED
#define PROGRAMBLOCKS_H_INCLUDED

#include "data_input.h"
#include <exception>
#include <cstring>
#include <iosfwd>
#include <iostream>
#include "DataStructures.h"

namespace prblocks
{
    class DataInputController final
    {

    public:
        explicit DataInputController(const size_t argc, const char** argv);

        std::string get_args_str() const {return args;}


        void debug()
        {
            std::cout << "Args:\n" << args << ".\n"
                      << "Write File:\n" << nameFileToWrite << ".\n";
        }


    private:
        //keys
        enum types{INT, STRING, CHAR, DOUBLE, NONE};
        argsprocessing::Key readFileKey = "-o";
        argsprocessing::Key saveDataKey = "-w";
        types typeDataKey = NONE;

        std::string nameFileToWrite = "None";

        std::string args;


        //helper funtions
       void init(const size_t argc, const char** argv); // initialization
       int read_data_from_file(std::ifstream &file);


    };




    class OperationSelectInterface final
    {
        OperationSelectInterface() = delete;
       ~OperationSelectInterface() = delete;
        OperationSelectInterface(const OperationSelectInterface&) = delete;
        OperationSelectInterface& operator=(const OperationSelectInterface&) = delete;

    public:
        template<typename T1, typename T2> static void selectDataStructure(const T1& dataCont, T2& sourceCont);
        static void selectAlgorithm();
        static void selectSort();
        static void convert();
    private:
    };  


    template<typename T1, typename T2>
    void OperationSelectInterface::selectDataStructure(const T1& dataCont, T2& sourceCont)
    {
        std::cout << "Test";
        // sourceCont.erase();
       // for(size_t i = 0; i < dataCont.size();++i)sourceCont.push(dataCont[i]);
    }

}




#endif // PROGRAMBLOCKS_H_INCLUDED
