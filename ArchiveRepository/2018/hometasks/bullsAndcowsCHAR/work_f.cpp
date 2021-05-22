#include "work_f.h"

void my_input(char (&us_a)[4])
{
     while(true){
        try
        {
            qesh_input(us_a);
            break;
        }
        catch(std::runtime_error &e)
        {
            std::cerr << e.what() << "Try again.\n";
            continue;
        }
    }
}
