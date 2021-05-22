#ifndef MY_LIST_H
#define MY_LIST_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class My_list
{
private:
    std::string name;
    std::vector<std::string> STR_LST;
public:
    My_list() :name("Unnamed"), STR_LST(){}
    My_list(const std::string &name_v)
            : name(name_v), STR_LST(){}
    My_list(const std::string &name_v,
            const std::vector<std::string> &STR_LST_V)
            : name(name_v), STR_LST(STR_LST_V){}
    My_list(const char* name_v,
            const std::vector<std::string> &STR_LST_V)
            : name(name_v), STR_LST(STR_LST_V){}
    My_list(const My_list &My_list_copy);

    void add_record(const std::string &record){STR_LST.push_back(record);}
    void add_record(const char* record){STR_LST.push_back(record);}
    std::string t_elem(size_t i)const
    {
        const int error_overflow = -1;
        if(STR_LST.size() - 1 < i) throw(error_overflow);
        return STR_LST[i];
    }
    void print_all();
    void del_record(size_t i);

    friend std::istream& operator>>(std::istream &is, My_list &i_data);
    friend std::ostream& operator<<(std::ostream &os, const My_list &o_data);

};
#endif // MY_LIST_H
