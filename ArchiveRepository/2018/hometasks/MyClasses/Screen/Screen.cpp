#include "Screen.h"


Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row+c];
}
void Screen::some_member() const
{
    ++access_ctr;
}
Screen::pos Screen::size()const
{
    return height * width;
}

