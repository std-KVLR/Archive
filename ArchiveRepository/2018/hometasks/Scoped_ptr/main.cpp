#include <iostream>
#include "Scoped_ptr.h"
#include "storage.h"
using namespace std;

void testf2(int *p)
{
    cout << "KEK";
}
void testf(int *p)
{
    testf2(p);
}

int main()
{
    int i = 2;
    Scoped_ptr test_s(10);
    Scoped_ptr test_s2;
    test_s2 = test_s;
    cout << "Hello world!" << endl;
    return 0;
}
