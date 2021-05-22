#ifndef INPUT_F_H
#define INPUT_F_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>


void input_number(int &val, const char *what_inp);
int input_for_sw();
void output_answer(const int &check, const int &range,
                   const int &comb_val, const int &comb_count,
                   const int &result_wo_rep, const int&result_w_rep);


#endif // WORK_F_H
