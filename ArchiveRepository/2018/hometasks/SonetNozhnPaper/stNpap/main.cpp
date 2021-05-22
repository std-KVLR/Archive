#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
using namespace std;
int Game_Started();
void generate_logic_sq(string (&gl)[5]);
int input_symb(string &buf_for_symb);
int logic_processing(const string &comp_str, const string &user_str);


int main()
{

	if(Game_Started() == -1) {cerr << "Error. Restart Game"; return -1;}
	return 0;

}



int Game_Started()
{
    cout << "Game continue to 3 wins, enter \"st\" \"kn\" \"pr\". (st > kn > pr > st).\n";
    string game_logic[5], buffer_for_symb;
    generate_logic_sq(game_logic);

    short user_w = 0, comp_w = 0, i = 0, regulator;
    while(user_w != 3 && comp_w != 3){
            cout <<"Enter you symbol: ";
            if(!input_symb(buffer_for_symb)) return -1;
            cout << "Computer symbol is: " << game_logic[i] << '\n';
            switch(logic_processing(game_logic[i++], buffer_for_symb))
            {
              case 0: ++user_w, ++comp_w; break;
              case 1: ++user_w; break;
              case 2: ++comp_w; break;
            }
            cout << "Current table is:\nuser: " << user_w << ' '
                 << "computer: " << comp_w << '\n';
            }
    if(user_w > comp_w) cout << "User win!";
    else if(user_w < comp_w) cout << "Computer win!";
    else cout << "Draw!";
    return 0;
}






void generate_logic_sq(string (&gl)[5])
{
        short randomizer;

        srand(time(NULL));
        for(int i = 0; i < 5; ++i){
        randomizer = 1 + rand() % 3;
        switch(randomizer)
        {
            case 1: gl[i] = "nozhnici"; break;
            case 2: gl[i] = "stone"; break;
            case 3: gl[i] = "paper"; break;
        }
    }
}
int input_symb(string &buf_for_symb)
{
    string symb;
    while(1){
        cin >> symb;
        if(symb != "kn" && symb != "pr" && symb != "st"){
                cerr << "Uncorrect symbol. Try again\n";
                continue;
        }
        else break;
        if(cin.fail()) return 0;
        }

    buf_for_symb = symb;
    return 1;
}

int logic_processing(const string &comp_str, const string &user_str)
{
    if(comp_str == user_str) return 0; //draw

    if(comp_str == "nozhnici" && user_str == "pr") return 2;
    if(comp_str == "paper" && user_str == "kn") return 1;

    if(comp_str == "stone" && user_str == "kn") return 2;
    if(comp_str == "nozhnici" && user_str == "st") return 1;

    if(comp_str == "paper" && user_str == "st") return 2;
    if(comp_str == "stone" && user_str == "pr") return 1;
}


