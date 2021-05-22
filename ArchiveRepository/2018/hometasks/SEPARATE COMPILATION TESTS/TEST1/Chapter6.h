#ifndef CHAPTER6_H
#define CHAPTER6_H
int exs6_3fact(int x)
{
    if(x != 1) return x * exs6_3fact(--x);
    return x;
}
#include <iostream>
int exs6_4fact()
{
    int x;
    std::cout << "Enter value: ", std::cin >> x;
    int fact = x;
    while(x != 1) fact *= --x;
    return fact;
}
int exs6_5(int x)
{
    if(x < 0) return x - (x*2);
    return x;
}
int exs6_7()
{
    static int i = 0;
    return i++;
}
#endif
