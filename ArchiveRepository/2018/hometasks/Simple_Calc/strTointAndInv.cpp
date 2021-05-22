#include "strTointAndInv.h"



int str_To_int(const string &ws)
{
	vector <string> sv = {"zero", "one", "two", "three", "fore", "five" , "six", "seven", "eight", "nine"};
	for(int i = 0; i < 10; ++i) if(sv[i] == ws) return i;
	throw(-1);
}
/*string int_To_Str(const int &i)
{
	vector <string> sv = {"zero", "one", "two", "three", "fore", "five" , "six", "seven", "eight", "nine"};
	if(i > 9 || i < 0) return -1;
	return sv[i];
}
*/
double test_Num(const string &ws)
{
    const char *p = &ws[0];
    if(isdigit(ws[0])){
        for(const auto &c : ws) {if(!isdigit(c)) throw(-1);}
        return atof(p);
    }
    else return str_To_int(ws);
}



