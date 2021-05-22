#include "Punct_stream.h"


Punct_stream& Punct_stream::operator>>(std::string& s)
{
    while (!(buffer >> s)) {
        if (buffer.bad() || !source.good()) return *this;
        buffer.clear();

        std::string line;
        getline(source, line);

        for(size_t i = 0; i < line.size(); ++i){
            if(is_whitespace(line[i])) line[i] = ' ';
            else if (!sensitive) line[i] = tolower(line[i]);

            buffer.str(line);
        }
    }
    return *this;
}

bool Punct_stream :: is_whitespace(char c)
{
    for(size_t i = 0; i < white.size(); ++i){
        if(c == white[i]) return true;
    }
    return false;
}

Punct_stream :: operator bool()
{
    return !(source.fail() || source.bad()) && source.good();
}








/*Punct_stream::Punct_stream()
{
    //ctor
}

Punct_stream::~Punct_stream()
{
    //dtor
}
*/
