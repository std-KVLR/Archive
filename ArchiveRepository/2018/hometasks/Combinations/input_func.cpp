#include "input_func.h"


void input_number(int &val, const char *what_inp)
{
    std::cout << "Enter " << what_inp << ":\n";
    std::cin >> val;
    if(std::cin.eof()){
        std::cout << "Program is stopped." << std::endl;
        exit(1);
    }
    if(!std::cin.good()) throw std::runtime_error("error: value must be a number\n");
    return;
}

int input_for_sw()
{
    enum sw{permutations = 1, combinations};
    int check;
    std::cout << "Choice calculation(1 for permutations, 2 for combinations):\n";
    std::cin >> check;
    if(std::cin.eof()){
        std::cout << "Program is stopped." << std::endl;
        exit(1);
    }
    if(!std::cin.good()) throw std::runtime_error("error: value must be a number\n");
    if(check != permutations &&
       check != combinations) throw std::runtime_error("error: the choice is made by the values 1 or 2\n");
    return check;
}

void output_answer(const int &check, const int &range,
                   const int &comb_val, const int &comb_count,
                   const int &result_wo_rep, const int& result_w_rep)
{
    std::string type_exp;
    if(check == 1) type_exp = "permutations";
    else if(check == 2) type_exp = "combinations";
    else throw std::runtime_error("error: check is invalid\n");

    std::cout << "For expression, where range = " << range
              << " and combination size = " << comb_val << ' '
              << type_exp << " is:\n"
              << "with repeat = " << result_w_rep << '\n'
              << "without repeat = " << result_wo_rep << ".\n"
              << "A common permission number is " << comb_count << '.'
              << std::endl;
}
