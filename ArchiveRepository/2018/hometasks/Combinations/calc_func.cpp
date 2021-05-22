#include "calc_func.h"


void calc_comb_all(const int &range, const int &comb_val, const int &check,
               int &perm_count, int &result_w_rep, int &result_wo_rep)
{
    if(range < 0 || comb_val < 0) throw(-2);
    perm_count = factorial(range);
    switch(check)
    {
    case permutations:
        if(calc_perm(range, comb_val, perm_count, result_w_rep, result_wo_rep) == -1){
            throw(-1);
        }
        return;
    case combinations:
        if(calc_comb(range, comb_val, perm_count, result_w_rep, result_wo_rep) == -1){
            throw(-1);
        }
        return;
    }

}
int calc_perm(const int &range, const int &comb_val,
               const int &perm_count, int &result_w_rep, int &result_wo_rep)
{
    if(range < comb_val) return -1;
    result_wo_rep = perm_count/factorial(range - comb_val);
    result_w_rep = pow(range, comb_val) + 0.5;
    return 0;
}
int calc_comb(const int &range, const int &comb_val,
               const int &perm_count, int &result_w_rep, int &result_wo_rep)
{
    if(range < comb_val) return -1;
    int comb_val_f = factorial(comb_val);
    result_wo_rep = perm_count/(comb_val_f * factorial(range - comb_val));
    result_w_rep = factorial(range + (comb_val - 1))/(comb_val_f * factorial(range - 1));
    return 0;
}
