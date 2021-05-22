#ifndef READING_TASK11_H
#define READING_TASK11_H

#include <iostream>
#include <string>
#include <sstream>
struct Reading_task11
{

    char syst = 'd';
    int value = 0;


    Reading_task11() = default;
    Reading_task11(std::istream& ist);

    char det(const std::string& str);


};

#endif // READING_TASK11_H
