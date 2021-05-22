#include <iostream>
#include "My_List.h"
using namespace std;


int main()
{
    My_list test_l;
    cin >> test_l >> test_l >> test_l;
    test_l.add_record("Kek2");
    test_l.add_record("Kek3");
    cout << test_l;
    test_l.print_all();
    return 0;
}
