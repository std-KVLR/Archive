#include <iostream>
#include <vector>
using namespace std;

int reverseAndOutputBits(unsigned x, unsigned position);

void studenBoo()
{
     unsigned quiz1 = 0, studentN;
     bool test;

 cout << "Enter student number: ";
 cin >> studentN;
 quiz1 |= (1 << studentN);

 test = reverseAndOutputBits(quiz1, 27);

 cout << "Is 27'tn student number have a " << test;
}

int reverseAndOutputBits(unsigned x, unsigned position)
{
    unsigned term = x;
    unsigned result = 0;

    term = (term & 0x55555555) << 1 | (term >> 1) & 0x55555555;
    term = (term & 0x33333333) << 2 | (term >> 2) & 0x33333333;
    term = (term & 0x0F0F0F0F) << 4 | (term >> 4) & 0x0F0F0F0F;
    term = (term << 24) | ((term & 0xFF00) << 8) | ((term >> 8) & 0xFF00) | (term >> 24);

    for(int i = 0, j = 31; i < 32; ++i, --j, term >>= 1){
            cout << j << "= " << (term & 1) << '\n';
            if(i == position) result = ((x >> i) & 1);
    }
    return static_cast <bool> (result);

}


int main()
{
  ì
  return 0;

}
