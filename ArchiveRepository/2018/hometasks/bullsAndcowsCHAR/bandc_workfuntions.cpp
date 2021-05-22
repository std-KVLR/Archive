#include "bandc_workfuntions.h"


void create_rand_sq(char (&task_a)[4])
{
    srand(time(NULL));
    for(size_t i = 0; i < 4; ++i){
            task_a[i] = 65 + rand () %(90 - 65);
            for(size_t j = 0; j < i;){
                if(task_a[i] == task_a[j]){
                    task_a[i] = 65 + rand () %(90 - 65);
                    j = 0;
                }
                else ++j;
            }
    }
}

void qesh_input(char (&us_a)[4])
{
    std::cout << "Input a four-character sequence from 1 to 9, characters should not be repeated:\n";
    std::string work_s;
    getline(std::cin, work_s);
    if(std::cin.eof()){std::cout << "Program execution terminated by user"; exit(1);}
    if(work_s.size() > 4) throw std::runtime_error("error: the sequence is too long, enter a FOUR character sequence\n");
    for(const auto &c : work_s) if (!isupper(c)) throw std::runtime_error("error: entered must be ONLY upper characters\n");
    for(short i = 0; i < 3; ++i){
         for(short j = i + 1; j < 4; ++j){
            if(work_s[i] == work_s[j]) throw std::runtime_error("error: the characters should NOT BE repeated\n");
         }
    }
    for(short i = 0; i < 4; ++i)
    {
        us_a[i] = work_s[i];
    }
}

void game_logic(char (&task_a)[4], char (&us_a)[4], short &bulls, short &cows)
{
    bulls = cows = 0;

    for(short i = 0; i < 4; ++i){
            if(us_a[i] != task_a[i]){
                for(short j = bulls; j < 4; ++j){
                    if(task_a[j] == us_a[i]){++cows; break;}
                }
            }
            else ++bulls;
    }
}
