#include <iostream>
#include "input_func.h"
#include "calc_func.h"
#include <cstdio>
#include <climits>

using namespace std;

int main()
{
    int range = 0, combination = 0;
    while(true)
    {
        try
        {
            if(range == 0)input_number(range, "range");
            if(combination == 0)input_number(combination, "combination size");
            int result_wo_rep, result_w_rep, perm_num, check = input_for_sw();
            calc_comb_all(range, combination, check, perm_num, result_w_rep, result_wo_rep);
            output_answer(check, range, combination, perm_num, result_wo_rep, result_w_rep);
            break;
        }
        catch(runtime_error &e)
        {
            cerr << e.what() << "Try again.\n";
            cin.clear();
            cin.ignore(255,'\n');
        }
        catch(int i)
        {
            if(i == -1)cerr << "error: combination size bigger then range\nTry again.\n";
            if(i == -2)cerr << "error: combination size or range less then zero\nTry again.\n";
            range = 0;
            combination = 0;
        }
    }
    return 0;
}
