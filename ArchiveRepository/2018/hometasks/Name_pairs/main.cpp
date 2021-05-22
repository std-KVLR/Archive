#include <iostream>
#include "Name_pairs.h"
using namespace std;



int main()
{
    Name_pairs test;
    test.read_names();
    test.read_ages();
    Name_pairs test2 = test;
    cout << test;
    cout << (test != test2);
    test.sort();
    cout << "Sorted: ";
    cout << test  << '\n';
    cout << (test != test2);
    return 0;
}
