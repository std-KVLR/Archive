#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
class Book
{
public:
    using str = std::string;

    Book() = default;
    Book(const str&, const str&, const str&,
         const str&, const str&, size_t, size_t, short);
    Book(const char*, const char*, const char*,
         const char*, const char*, size_t, size_t, short);
    Book(const char* name_v):name(name_v) {}
    Book(std::istream &is):Book() {read(is);}


    std::istream& read(std::istream&);
private:
    str ISBN;
    str name;
    str genre;
    str author_name;
    str binding;
    size_t page_num = 0;
    size_t cost = 0;
    short rating = 0;
};
#endif // BOOK_H
