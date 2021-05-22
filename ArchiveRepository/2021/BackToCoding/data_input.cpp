#include "data_input.h"


void argsprocessing::format::string_format_char(std::string &str_buf, const char* source)
{
    if(!str_buf.empty())str_buf.clear();

    for(size_t i = 0; source[i] != '\0'; ++i){
        str_buf.push_back(source[i]);
        str_buf.push_back(' ');
    }
}


void argsprocessing::format::string_format_double(std::string &str_buf, const char* source)
{
    if(!str_buf.empty())str_buf.clear();

    for(size_t i = 0; source[i] != '\0'; ++i){
        if( isdigit(source[i]) || (source[i] == '.' && isdigit(source[i + 1])) ) str_buf.push_back(source[i]);
        else if(isdigit(source[i - 1])) str_buf.push_back(' ');
        }
}


void argsprocessing::format::string_format_int(std::string &str_buf, const char* source)
{
    if(!str_buf.empty())str_buf.clear();

    for(size_t i = 0; source[i] != '\0'; ++i){
        if(isdigit(source[i])){
            str_buf.push_back(source[i]);
        }
        else if(isdigit(source[i - 1])) str_buf.push_back(' ');
    }
}

