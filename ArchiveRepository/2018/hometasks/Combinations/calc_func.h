#ifndef CALC_F_H
#define CALC_F_H

enum sw{permutations = 1, combinations};

#include <cmath>
inline int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void calc_comb_all(const int &range, const int &comb_val, const int &check,
               int &perm_count, int &result_w_rep, int &result_wo_rep);
int calc_perm(const int &comb_val, const int &check,
               const int &perm_count, int &result_w_rep, int &result_wo_rep);
int calc_comb(const int &comb_val, const int &check,
               const int &perm_count, int &result_w_rep, int &result_wo_rep);

#endif // WORK_F_H
