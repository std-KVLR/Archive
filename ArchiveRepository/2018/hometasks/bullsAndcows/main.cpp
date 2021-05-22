#include <iostream>
#include "bandc_workfuntions.h"
#include "work_f.h"

using namespace std;

int main()
{
    short task_ar[4] = {0};
    short user_ar[4] = {0};
    short bulls, cows;

    create_rand_sq(task_ar);
    for(auto & i: task_ar) cout << i << ' ';

    while(bulls != 4){
        my_input(user_ar);
        game_logic(task_ar, user_ar, bulls, cows);
        cout << "Bulls = " << bulls << "; "
             << "Cows = " << cows << '\n';
    }
    cout << "Thanks for the game, it was fun :)";
    return 0;
}
