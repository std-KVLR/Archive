#ifndef PUNCT_STREAM_H
#define PUNCT_STREAM_H

#include <iostream>
#include <sstream>

class Punct_stream
{
    public:
        Punct_stream(std::istream &is)
                    :source(is), sensitive(true) {}


        void whitespace(const std::string& s) { white = s; } //создает строку разделитеей
        void add_white(char c) { white += c; } //добавляет символ в набор разделитей
        bool is_whitespace(char c); // является ли с разделителем

        void case_sensitive (bool b) { sensitive = b; }
        bool is_case_sensitive() { return sensitive ; }

        Punct_stream& operator>>(std::string &s);
        operator bool();
    private:
        std::istream& source;
        std::istringstream buffer;
        std::string white;
        bool sensitive;
};

#endif // PUNCT_STREAM_H
