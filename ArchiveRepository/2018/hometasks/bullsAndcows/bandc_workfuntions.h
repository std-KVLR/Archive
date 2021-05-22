#ifndef BANC_WF_H
#define BANC_WF_H

#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cctype>
#include <stdexcept>

void create_rand_sq(short (&task_a)[4]);
void qesh_input(short (&us_a)[4]);
void game_logic(short (&task_a)[4], short (&us_a)[4], short &bulls_r, short &cows_r);

#endif // BANC_WF_H
